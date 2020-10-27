
#include "lua2cpp.h"

// 测试lua中的变量
void test_varriable(lua_State *L)
{
    // 字符串
    lua_getglobal(L, "name");
    if (lua_isstring(L, -1))
    {
        std::cout << lua_tostring(L, -1) << endl;   
    }
    // 数字
    lua_getglobal(L, "age");
    if (lua_isnumber(L, -1))
    {
        std::cout << lua_tonumber(L, -1) << endl;   
    }
    // bool
    lua_getglobal(L, "isGay");
    if (lua_isboolean(L, -1))
    {
        std::cout << lua_toboolean(L, -1) << endl;   
    }
}

// 测试cpp调用lua中的function
void test_function(lua_State *L)
{
    int ret;
    lua_getglobal(L, "add");
    lua_pushnumber(L, 10);
    lua_pushnumber(L, 20);
    ret = lua_pcall(L, 2, 1, 0);
    if (ret)
    {
        std::cout << "pcall error" << endl;
    }
    if (lua_isnumber(L, -1))
    {
        cout << "result is " << lua_tonumber(L, -1) << endl;
    }
}

// 测试lua中的require
void test_require(lua_State *L)
{
    int ret;
    // 写法1
    lua_getglobal(L, "lib");
    lua_getfield(L, -1, "_name");
    if (lua_isstring(L, -1))
    {
        std::cout << lua_tostring(L, -1) << endl;   
    }

    lua_getglobal(L, "lib");
    lua_getfield(L, -1, "sex");
    if (lua_isstring(L, -1))
    {
        std::cout << lua_tostring(L, -1) << endl;   
    }
    // 写法2
    lua_getglobal(L, "lib");
    lua_getfield(L, -1, "_name");
    if (lua_isstring(L, -1))
    {
        std::cout << lua_tostring(L, -1) << endl;   
    }

    lua_getfield(L, -2, "sex");
    if (lua_isstring(L, -1))
    {
        std::cout << lua_tostring(L, -1) << endl;   
    }
    // 写法3
    lua_getglobal(L, "lib");
    lua_pushstring(L, "_name");
    lua_gettable(L, -2);
    if (lua_isstring(L, -1))
    {
        std::cout << lua_tostring(L, -1) << endl;   
    }

    lua_pushstring(L, "sex");
    lua_gettable(L, -3);
    if (lua_isstring(L, -1))
    {
        std::cout << lua_tostring(L, -1) << endl;   
    }

    lua_getglobal(L, "add");
    lua_pushnumber(L, 100);
    lua_pushnumber(L, 200);
    lua_pcall(L, 2, 1, 0);
    if (lua_isnumber(L, -1))
    {
        std::cout << lua_tonumber(L, -1) << endl;   
    }
}

// 测试lua调用cpp的变量
void test_cppVarriable(lua_State *L)
{
    // 普通变量
    lua_pushstring(L, "小米");
    lua_setglobal(L, "name");
    lua_pushnumber(L, 26);
    lua_setglobal(L, "age");
    lua_pushstring(L, "卖屁股的");
    lua_setglobal(L, "professional");
    lua_pushboolean(L, 1);
    lua_setglobal(L, "isGay");
    // 表
    // 创建空表
    lua_newtable(L);
    lua_pushstring(L, "小米");
    lua_setfield(L, -2, "name");
    lua_pushnumber(L, 26);
    lua_setfield(L, -2, "age");
    lua_pushstring(L, "卖屁股的");
    lua_setfield(L, -2, "professional");
    lua_pushboolean(L, 1);
    lua_setfield(L, -2, "isGay");
    lua_setglobal(L, "person");
}

// 测试lua调用cpp的函数
void test_cppFunction(lua_State *L)
{
    // 注册函数
    lua_register(L, "add", pkgAdd);
}

double add(double x, double y)
{
    return x+y;
}

// 包装的cpp函数
int pkgAdd(lua_State *L)
{
    int num = lua_gettop(L);
    if (num == 2)
    {
        double number1, number2;
        if (lua_isnumber(L, 1) && lua_isnumber(L, 2))
        {
            number1 = lua_tonumber(L, 1);
            number2 = lua_tonumber(L, 2);
            double result = add(number1, number2);
            lua_pushnumber(L, result);
        }
    }
    return 1;
}

int lua_openmylib(lua_State *L)
{
    // 创建新的表将所有函数放在这个表中
    luaL_newlib(L, mylibs_funcs);
    return 1;
}

// 测试采用模块包装函数
void test_cppModuleFunction(lua_State *L)
{
    const luaL_Reg *lib = lua_reg_libs;
    for (; lib->func; lib++)
    {
        luaL_requiref(L, lib->name, lib->func, 1);
        // 移除该模块
        lua_pop(L, 1);
    }
}

// 测试cpp类注册为模块形式
void test_cppClassModule(lua_State *L)
{
    // 基础lua库
    luaL_openlibs(L);
    // 基础类注册
    lua_baseClass_open_module(L);
}

// 测试cpp类以面向对象形式注册
void test_cppClassOOP(lua_State *L)
{
    // 基础lua库
    luaL_openlibs(L);
    // 基础类注册
    lua_baseClass_open_oop(L);
}

