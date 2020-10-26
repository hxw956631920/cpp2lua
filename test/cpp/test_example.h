

#ifndef __TEST_EXAMPLE_H_
#define __TEST_EXAMPLE_H_

/**
 * 测试用例数组配置表
 * **/

#include "lua2cpp.h"

#define MAX_TEST_NUMBER 1024

typedef void (*testFunction)(lua_State *L);

/**
 * 类别
 * Cpp to lua
 * lua to cpp
 * **/
enum Type{
    CPP2LUA,
    LUA2CPP
};

typedef struct ExampleStruct{
    testFunction handler;//测试用例函数
    char* testFile;//测试用例lua文件
    Type type;
}ExampleStruct;

// 获取用例
int getExample(char *fileName, ExampleStruct *example);

#endif
