# cpp2lua
this repository is my own repository for learning how lua interacts with cpp 

## branch
### main



## 快速安装指南
1. git clone https://github.com/hxw956631920/cpp2lua.git
2. cd cpp2lua/test/cpp
3. make
4. 执行 ./lua_test_c [example]
eg. ./lua_test_c ../lua/test_function.lua (测试cpp读取执行lua函数)

## 目录结构
.
├── ./README.md
└── ./test
    ├── ./test/cpp
    │   ├── ./test/cpp/Makefile
    │   ├── ./test/cpp/liblua.a
    │   ├── ./test/cpp/lua2cpp.cpp
    │   ├── ./test/cpp/lua2cpp.h
    │   ├── ./test/cpp/lua_test_c
    │   ├── ./test/cpp/lua_test_c.cpp
    │   ├── ./test/cpp/test_example.cpp
    │   └── ./test/cpp/test_example.h
    └── ./test/lua
        ├── ./test/lua/lib.lua
        ├── ./test/lua/test_CppFunction.lua
        ├── ./test/lua/test_CppModuleFunction.lua
        ├── ./test/lua/test_CppVarriable.lua
        ├── ./test/lua/test_function.lua
        ├── ./test/lua/test_require.lua
        └── ./test/lua/test_varriable.lua

3 directories, 16 files
