
#ifndef __LUA_TMCOLOR_BINDING_H_
#define __LUA_TMCOLOR_BINDING_H_

#include "luastd.h"
#include <iostream>
#include "tmcolor.h"

using namespace std;

int lua_tmcolor_FLAG(lua_State *L);

int lua_tmcolor_setFontThickness(lua_State *L);

int lua_tmcolor_setFontColor(lua_State *L);

int lua_tmcolor_setBgColor(lua_State *L);

int lua_openFontAttributeLib(lua_State *L);

// 将c++函数封装成模块
static const luaL_Reg FontAttributeLib[] = {
    {"setFontThickness", lua_tmcolor_setFontThickness},
    {"setFontColor", lua_tmcolor_setFontColor},
    {"setBgColor", lua_tmcolor_setBgColor},
    {NULL, NULL}
};

#endif