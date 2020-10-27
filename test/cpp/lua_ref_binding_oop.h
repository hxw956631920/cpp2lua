
#ifndef _LUA_REF_BIND_OOP_H_
#define _LUA_REF_BIND_OOP_H_

// lua binding 面向对象版本

// 引入lua标准头文件库
#include "luastd.h"
#include "Ref.h"

// 创建ref对象
int lua_ref_create_oop(lua_State *L);

// 
int lua_ref_retain_oop(lua_State *L);

int lua_ref_release_oop(lua_State *L);

int lua_ref_getRefCount_oop(lua_State *L);

// 测试Cpp类
static const luaL_Reg lua_ref_libs_oop[] = {
    {"create", lua_ref_create_oop},
    {"retain", lua_ref_retain_oop},
    {"release", lua_ref_release_oop},
    {"getRefCount", lua_ref_getRefCount_oop},
    {NULL, NULL}
};

static const luaL_Reg lua_ref_libs_create_oop[] = {
    {"create", lua_ref_create_oop},
    {NULL, NULL}
};

int lua_ref_register_oop(lua_State *L);

static const luaL_Reg lua_baseClass_libs_oop[] = {
    {"Ref", lua_ref_register_oop},
    {NULL, NULL}
};

int lua_baseClass_open_oop(lua_State *L);


#endif