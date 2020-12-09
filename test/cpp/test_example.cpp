

#include "test_example.h"

ExampleStruct test_example[MAX_TEST_NUMBER] = {
    {test_varriable, (char *)"../lua/test_varriable.lua", LUA2CPP},
    {test_function, (char *)"../lua/test_function.lua", LUA2CPP},
    {test_require, (char *)"../lua/test_require.lua", LUA2CPP},
    {test_cppFunction, (char *)"../lua/test_CppFunction.lua", CPP2LUA},
    {test_cppVarriable, (char *)"../lua/test_CppVarriable.lua", CPP2LUA},
    {test_cppModuleFunction, (char *)"../lua/test_CppModuleFunction.lua", CPP2LUA},
    {test_cppClassModule, (char *)"../lua/test_CppClassModule.lua", CPP2LUA},
    {test_cppClassOOP, (char *)"../lua/test_CppClassOOP.lua", CPP2LUA},
    {test_metatable, (char *)"../lua/test_metatable.lua", LUA2CPP},
    {test_cppMetatable, (char *)"../lua/test_CppMetatable.lua", CPP2LUA},
    {test_cppInheritance, (char *)"../lua/test_CppInheritance.lua", CPP2LUA},
    {NULL, NULL}
};

int getExample(char *fileName, ExampleStruct *example)
{
    for (int i = 0; test_example[i].handler != NULL; i++)
    {
        if (strcmp(test_example[i].testFile, fileName) == 0)
        {
            strcpy(example->testFile, test_example[i].testFile);
            example->handler = test_example[i].handler;
            example->type = test_example[i].type;
            return 0;
        }
    }
    return 1;
}