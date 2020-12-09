

#include "lua_node_binding.h"

// 创建node对象
int lua_Node_create(lua_State *L)
{
    Node ** obj = (Node **)lua_newuserdata(L, sizeof(Node));
    *obj = new Node();
    luaL_getmetatable(L, "NodeClass");
    lua_setmetatable(L, -2);
    return 1;
}

// 设置位置
int lua_Node_setPosition(lua_State *L)
{
    Node ** obj = (Node **)luaL_checkudata(L, 1, "NodeClass");
    luaL_argcheck(L, obj != NULL, 1, "invalid user data");
    float x = lua_tonumber(L, 2);
    float y = lua_tonumber(L, 3);
    (*obj)->setPosition(x, y);
    return 1;
}

// 获取位置
int lua_Node_getPosition(lua_State *L)
{
    Node ** obj = (Node **)luaL_checkudata(L, 1, "NodeClass");
    luaL_argcheck(L, obj != NULL, 1, "invalid user data");
    Vec2 pos = (*obj)->getPosition();
    lua_getglobal(L, "ccp");
    if (!lua_istable(L, -1))
    {
        lua_newtable(L);
    }
    lua_pushnumber(L, pos._x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, pos._y);
    lua_setfield(L, -2, "y");
    if (!lua_istable(L, -1))
    {
        lua_setglobal(L, "ccp");
    }
    return 1;
}

// 移除
int lua_Node_remove(lua_State *L)
{
    Node ** obj = (Node **)luaL_checkudata(L, 1, "NodeClass");
    luaL_argcheck(L, obj != NULL, 1, "invalid user data");
    (*obj)->remove();
    return 1;
}

// 模块注册
int lua_Node_Md_register(lua_State *L)
{
    luaL_newmetatable(L, "NodeClass");
    lua_pushcfunction(L, lua_Node_Mt_index);
    lua_setfield(L, -2, "__index");
    // 注册元表方法
    luaL_setfuncs(L, lua_Node_Mt_Fun, 0);
    // 注册接口
    luaL_newlib(L, lua_Node_Md_Fun);
    return 1;
}

// 导入模块
void lua_Node_open(lua_State *L)
{
    const luaL_Reg *lua_reg = lua_Node_Md;
    luaL_requiref(L, lua_reg->name, lua_reg->func, 1);
    lua_pop(L, 1);
}

// 表查找函数
int lua_Node_Mt_index(lua_State *L)
{
    int argc = lua_gettop(L);
    if (argc == 2)
    {
        if (lua_isuserdata(L, -2))
        {
            // 获取到目标表的元表
            lua_getmetatable(L, -2);
            // 查询元表key对应的value
            const char *key = lua_tostring(L, -2);
            lua_getfield(L, -1, lua_tostring(L, -2));
            if (lua_isnil(L, -1))
            {
                // 获取到目标表的元表的元表 
                luaL_getmetatable(L, "RefClass");
                lua_getfield(L, -1, key);
            }
        }
    }
    return 1;
}