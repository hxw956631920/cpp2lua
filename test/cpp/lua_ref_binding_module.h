
#ifndef __LUA_REF_BINDING_MODULE_H_
#define __LUA_REF_BINDING_MODULE_H_

// 将c++类注册成模块形式供lua调用

// 引入lua标准头文件库
#include "luastd.h"
#include "Ref.h"



// 创建ref对象
int lua_ref_create_module(lua_State *L);

// 
int lua_ref_retain_module(lua_State *L);

int lua_ref_release_module(lua_State *L);

int lua_ref_getRefCount_module(lua_State *L);

// 测试Cpp类
static const luaL_Reg lua_ref_libs_module[] = {
    {"create", lua_ref_create_module},
    {"retain", lua_ref_retain_module},
    {"release", lua_ref_release_module},
    {"getRefCount", lua_ref_getRefCount_module},
    {NULL, NULL}
};

int lua_ref_register_module(lua_State *L);

static const luaL_Reg lua_baseClass_libs_module[] = {
    {"Ref", lua_ref_register_module},
    {NULL, NULL}
};

int lua_baseClass_open_module(lua_State *L);

#endif