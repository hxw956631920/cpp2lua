


#include <iostream>
#include <string.h>
using namespace std;

extern "C"
{
    // lua标准库
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}
// 自定义头文件
#include "test_example.h"

static const luaL_Reg customLib[] = {
    {"FontAttribute", lua_openFontAttributeLib},
    {NULL, NULL}
};

static const luaL_Reg customConst[] = {
    {"FontAttribute", lua_tmcolor_FLAG},
    {NULL, NULL}
};

void registerCustomLib(lua_State *L)
{
    const luaL_Reg *lib = customLib;
    // 注册模块的函数
    for (; lib->func; lib++)
    {
        luaL_requiref(L, lib->name, lib->func, 1);
        // 移除该模块
        lua_pop(L, 1);
    }
    // 注册模块对应的常量
    lib = customConst;
    for (; lib->func; lib++)
    {
        lib->func(L);
        // 移除该模块
        lua_pop(L, 1);
    }
    
    // luaL_requiref 等价于如下代码
    // luaL_getsubtable(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
    // lua_getfield(L, -1, "FontAttribute");  /* LOADED[modname] */
    // if (!lua_toboolean(L, -1)) {  /* package not already loaded? */
    //     lua_pop(L, 1);  /* remove field */
    // /* 
    //     相当于压入 lua_openFontAttributeLib 函数
    //     压入其参数 FontAttribute
    // */
    //     lua_pushcfunction(L, lua_openFontAttributeLib);

    //     /* 
    //         lua_pushcfunction 的原型如下
    //         lua_pushcclosure(L, (f), 0)
    //     */
    //     lua_pushstring(L, "FontAttribute");  /* argument to open function */
    // /*  
    //     lua_call 也是调用栈中的函数 原型如下
    //     void lua_call (lua_State *L, int nargs, int nresults);
    //     nargs表示调用函数参数个数  nresults表示函数返回值个数
    //     lua_call于lua_pcall十分相似 据网上查资料说 lua_call的运行是无保护的，在
    //     发生错误时抛出错误而不是返回错误代码 
    //     考证资料地址:https://blog.csdn.net/fengbangyue/article/details/7342274  
    // */
    // /* 
    //     不太理解的地方 lua_openFontAttributeLib 分明要传的参数是lua_State *L类型
    //     可是这里却调用的是 string 这就很奇怪
    // */
    //     lua_call(L, 1, 1);  /* call 'openf' to open module */
    //     lua_pushvalue(L, -1);  /* make copy of module (call result) */
    //     lua_setfield(L, -3, "FontAttribute");  /* LOADED[modname] = module */
    // }
    // lua_remove(L, -2);  /* remove LOADED table */
    // if (glb) {
    //     lua_pushvalue(L, -1);  /* copy of module */
    //     lua_setglobal(L, "FontAttribute");  /* _G[modname] = module */
    // }
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        // 创建lua栈
        lua_State *L = luaL_newstate();
        luaL_openlibs(L);
        registerCustomLib(L);
        if (L == NULL)
        {
            return 0;
        }
        ExampleStruct *example = new ExampleStruct;
        example->testFile = new char[100];
        memset(example->testFile, '\0', 100);
        // memset(example, 0, sizeof(ExampleStruct));
        if (getExample(argv[1], example) == 0)
        {
            if (example->type == CPP2LUA)
            {
                example->handler(L);
                // 加载lua文件
                int ret = luaL_loadfile(L, example->testFile);
                if (ret)
                {
                    std::cout << "load file error" << endl;
                }
                ret = lua_pcall(L, 0, 0, 0);
                if (ret)
                {
                    std::cout << "pcall error" << endl;
                    return 0;
                }
            }
            else if (example->type == LUA2CPP)
            {
                // 加载lua文件
                int ret = luaL_loadfile(L, example->testFile);
                if (ret)
                {
                    std::cout << "load file error" << endl;
                }
                ret = lua_pcall(L, 0, 0, 0);
                if (ret)
                {
                    std::cout << "pcall error" << endl;
                    return 0;
                }
                // 执行对应的测试函数
                example->handler(L);
            }
        }
        else
        {
            std::cout << "get example failed" << endl;
        }
        
        lua_close(L);
    }
    return 0;
}