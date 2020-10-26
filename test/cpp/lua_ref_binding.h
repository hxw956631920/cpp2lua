
#ifndef __LUA_REF_BINDING_H_
#define __LUA_REF_BINDING_H_

// 引入lua标准头文件库
#include "luastd.h"
#include "Ref.h"

// 创建ref对象
int lua_ref_create(lua_State *L);

// 
int lua_ref_retain(lua_State *L);

int lua_ref_release(lua_State *L);

int lua_ref_getRefCount(lua_State *L);

// 测试Cpp类
static const luaL_Reg lua_ref_libs[] = {
    {"create", lua_ref_create},
    {"retain", lua_ref_retain},
    {"release", lua_ref_release},
    {"getRefCount", lua_ref_getRefCount},
    {NULL, NULL}
};

int lua_ref_register(lua_State *L);

static const luaL_Reg lua_baseClass_libs[] = {
    {"Ref", lua_ref_register},
    {NULL, NULL}
};

int lua_baseClass_open(lua_State *L);

#endif