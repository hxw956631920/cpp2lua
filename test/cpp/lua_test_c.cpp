


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

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        // 创建lua栈
        lua_State *L = luaL_newstate();
        luaL_openlibs(L);
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