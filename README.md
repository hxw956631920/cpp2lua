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
├── Lua与c交互记录文档.docx
├── README.md
├── lua如何注册c++对象.docx
└── test
    ├── cpp
    │   ├── Makefile
    │   ├── Ref.cpp
    │   ├── Ref.h
    │   ├── debugTool.cpp
    │   ├── debugTool.h
    │   ├── liblua.a
    │   ├── lua2cpp.cpp
    │   ├── lua2cpp.h
    │   ├── lua_ref_binding_module.cpp
    │   ├── lua_ref_binding_module.h
    │   ├── lua_ref_binding_oop.cpp
    │   ├── lua_ref_binding_oop.h
    │   ├── lua_test_c
    │   ├── lua_test_c.cpp
    │   ├── lua_tmcolor_binding.cpp
    │   ├── lua_tmcolor_binding.h
    │   ├── luastd.h
    │   ├── test_example.cpp
    │   ├── test_example.h
    │   ├── tmcolor.cpp
    │   └── tmcolor.h
    └── lua
        ├── lib.lua
        ├── test_CppClassModule.lua
        ├── test_CppClassOOP.lua
        ├── test_CppFunction.lua
        ├── test_CppMetatable.lua
        ├── test_CppModuleFunction.lua
        ├── test_CppVarriable.lua
        ├── test_function.lua
        ├── test_metatable.lua
        ├── test_require.lua
        └── test_varriable.lua

3 directories, 35 files
