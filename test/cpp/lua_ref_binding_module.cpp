

#include "lua_ref_binding_module.h"

// 创建ref对象
int lua_ref_create_module(lua_State *L)
{
    // 分配一块大小为 sizeof(Ref *) 的内存块放置于栈顶
    Ref **obj = (Ref **)lua_newuserdata(L, sizeof(Ref *));
    // 让内存块指向一个Ref对象
    *obj = new Ref();
    return 1;
}

// 
int lua_ref_retain_module(lua_State *L)
{
    // 从栈底返回对象
    Ref **obj = (Ref **)lua_touserdata(L, 1);
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

int lua_ref_release_module(lua_State *L)
{
    // 从栈底返回对象
    Ref **obj = (Ref **)lua_touserdata(L, 1);
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

int lua_ref_getRefCount_module(lua_State *L)
{
    // 从栈底返回对象
    Ref **obj = (Ref **)lua_touserdata(L, 1);
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




int lua_baseClass_open_module(lua_State *L)
{
    const luaL_Reg *lua_reg = lua_baseClass_libs_module;
    for (; lua_reg->func; lua_reg++)
    {
        luaL_requiref(L, lua_reg->name, lua_reg->func, 1);
        lua_pop(L, 1);
    }
    return 1;
}

int lua_ref_register_module(lua_State *L)
{
    luaL_newlib(L, lua_ref_libs_module);
    return 1;
}