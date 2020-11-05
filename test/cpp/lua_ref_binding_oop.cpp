



#include "lua_ref_binding_oop.h"

// 创建ref对象
int lua_ref_create_oop(lua_State *L)
{
    Ref **obj = (Ref **)lua_newuserdata(L, sizeof(Ref *));
    *obj = new Ref();
    luaL_getmetatable(L, "RefClass");
    lua_setmetatable(L, -2);
    return 1;
}

// 
int lua_ref_retain_oop(lua_State *L)
{
    // 从栈底返回对象
    Ref **obj = (Ref **)luaL_checkudata(L, 1, "RefClass");
    luaL_argcheck(L, obj != NULL, 1, "invalid user data");
    int argc = lua_gettop(L) - 1;
    if (argc == 0)
    {
        (*obj)->retain();
        return 1;
    }
    else
    {
        std::cout << "argc should" << argc << endl;
        return 0;
    }
}

int lua_ref_release_oop(lua_State *L)
{
    // 从栈底返回对象
    Ref **obj = (Ref **)luaL_checkudata(L, 1, "RefClass");
    luaL_argcheck(L, obj != NULL, 1, "invalid user data");
    int argc = lua_gettop(L) - 1;
    if (argc == 0)
    {
        (*obj)->release();
        return 1;
    }
    else
    {
        std::cout << "argc should" << argc << endl;
        return 0;
    }
}

int lua_ref_getRefCount_oop(lua_State *L)
{
    // 从栈底返回对象
    Ref **obj = (Ref **)luaL_checkudata(L, 1, "RefClass");
    luaL_argcheck(L, obj != NULL, 1, "invalid user data");
    int argc = lua_gettop(L) - 1;
    if (argc == 0)
    {
        // 清空stack
        // lua_settop(L, 0);

        int refCount = (*obj)->getRefCount();

        lua_pushinteger(L, refCount);
        return 1;
    }
    else
    {
        std::cout << "argc should" << argc << endl;
        return 0;
    }
}




int lua_baseClass_open_oop(lua_State *L)
{
    const luaL_Reg *lua_reg = lua_baseClass_libs_oop;
    for (; lua_reg->func; lua_reg++)
    {
        luaL_requiref(L, lua_reg->name, lua_reg->func, 1);
        lua_pop(L, 1);
    }
    return 1;
}

int lua_ref_register_oop(lua_State *L)
{
    // 创建全局元表 如果LUA_REGISTRYINDEX注册表中无此元表，则创建一个新表加入到该注册表中
    luaL_newmetatable(L, "RefClass");
    // 将元表作为副本压栈到-1, 一开始创建的元表位置则变为-2
    lua_pushvalue(L, -1);
    // 设置自己为自己的元方法 也就是对象找不到方法时要通过对象的元表去找方法 不设置的话就报错
    lua_setfield(L, -2, "__index");

    // 成员函数注册到元表中
    luaL_setfuncs(L, lua_ref_libs_oop, 0);
    // 创建一个新的表 构造函数注册到其中
    luaL_newlib(L, lua_ref_libs_create_oop);
    return 1;
}