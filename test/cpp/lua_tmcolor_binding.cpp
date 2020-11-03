

#include "lua_tmcolor_binding.h"

int lua_tmcolor_FLAG(lua_State *L)
{
    lua_getglobal(L, "FontAttribute");
    lua_pushinteger(L, FC_PURPLE);
    lua_setfield(L, -2, "FC_PURPLE");
    return 0;
}

int lua_tmcolor_setFontThickness(lua_State *L)
{
    int argc = lua_gettop(L);
    if (argc == 2)
    {
        string str;
        FontThickness flag;
        string result;
        bool ok = lua_isstring(L, 1);
        if (ok)
        {
            str = lua_tostring(L, 1);
        }
        ok = lua_isinteger(L, 2);
        if (ok)
        {
            flag = (FontThickness)lua_tointeger(L, 2);
        }
        if (ok)
        {
            result = setFontThickness(str, flag);
            lua_pushlstring(L, result.c_str(), (size_t)result.length());
            return 1;
        }
    }
    return 0;
}

int lua_tmcolor_setFontColor(lua_State *L)
{
    int argc = lua_gettop(L);
    if (argc == 2)
    {
        string str;
        FontColor flag;
        string result;
        bool ok = lua_isstring(L, 1);
        if (ok)
        {
            str = lua_tostring(L, 1);
        }
        ok = lua_isinteger(L, 2);
        if (ok)
        {
            flag = (FontColor)lua_tointeger(L, 2);
        }
        if (ok)
        {
            result = setFontColor(str, flag);
            lua_pushlstring(L, result.c_str(), (size_t)result.length());
            return 1;
        }
    }
    return 0;
}

int lua_tmcolor_setBgColor(lua_State *L)
{
    int argc = lua_gettop(L);
    if (argc == 2)
    {
        string str;
        BgColor flag;
        string result;
        bool ok = lua_isstring(L, 1);
        if (ok)
        {
            str = lua_tostring(L, 1);
        }
        ok = lua_isinteger(L, 2);
        if (ok)
        {
            flag = (BgColor)lua_tointeger(L, 2);
        }
        if (ok)
        {
            result = setBgColor(str, flag);
            lua_pushlstring(L, result.c_str(), (size_t)result.length());
            return 1;
        }
    }
    return 0;
}

int lua_openFontAttributeLib(lua_State *L)
{
    luaL_newlib(L, FontAttributeLib);
    // lua_tmcolor_FLAG(L);
    return 1;
}
