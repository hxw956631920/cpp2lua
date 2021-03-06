
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

#include "lua_ref_binding_module.h"
#include "lua_ref_binding_oop.h"
#include "lua_node_binding.h"
#include "lua_tmcolor_binding.h"

#include <iostream>
using namespace std;

// 测试lua中的变量
void test_varriable(lua_State *L);

// 测试lua中的函数
void test_function(lua_State *L);

// 测试lua中的require
void test_require(lua_State *L);

// 测试lua中的元表
void test_metatable(lua_State *L);

// 测试lua调用cpp的变量
void test_cppVarriable(lua_State *L);

// __index元方法
int indexMethod(lua_State *L);

// __newIndex元方法
int newindexMethod(lua_State *L);

// 测试lua调用cpp创建的表和为表设置元表
void test_cppMetatable(lua_State *L);

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

// 测试cpp类注册为模块形式
void test_cppClassModule(lua_State *L);

// 测试cpp类以面向对象形式注册
void test_cppClassOOP(lua_State *L);

// 测试cpp类继承
void test_cppInheritance(lua_State *L);

#endif