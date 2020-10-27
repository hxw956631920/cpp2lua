
#ifndef __LUA2CPP_H_
#define __LUA2CPP_H_

/**
 * 测试用例头文件
 * 该文件中定义了如下测试用例
 * 1.cpp调用lua中的变量
 * 2.cpp调用lua中的function
 * 3.lua中使用requre，cpp查看其结构
 * 4.lua中调用cpp传进来的变量
 * 5.lua中调用cpp中压栈进来的函数
 * 6.lua中调用cpp封装成lua模块的函数
 * 7.
 * **/

// 引入lua标准头文件库
#include "lua_ref_binding_module.h"

#include <iostream>
using namespace std;

// 测试lua中的变量
void test_varriable(lua_State *L);

// 测试lua中的函数
void test_function(lua_State *L);

// 测试lua中的require
void test_require(lua_State *L);

// 测试lua调用cpp的变量
void test_cppVarriable(lua_State *L);

// 测试lua调用cpp的函数
void test_cppFunction(lua_State *L);

// 入栈的cpp函数
double add(double x, double y);
// 包装的cpp函数
int pkgAdd(lua_State *L);

// 将c++函数封装成模块
static const luaL_Reg mylibs_funcs[] = {
    {"add", pkgAdd},
    {NULL, NULL}
};

// 自己的库函数
int lua_openmylib(lua_State *L);

static const luaL_Reg lua_reg_libs[] = {
    {"base", luaopen_base},
    {"mylib", lua_openmylib},
    {NULL, NULL}
};

// 测试采用模块包装函数
void test_cppModuleFunction(lua_State *L);

// 测试cpp类
void test_cppClass(lua_State *L);

#endif