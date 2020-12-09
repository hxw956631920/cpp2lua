
#ifndef __LUA_NODE_BINDING_H_
#define __LUA_NODE_BINDING_H_

#include "luastd.h"
#include "Node.h"
#include "debugTool.h"

// 创建node对象
int lua_Node_create(lua_State *L);

// 设置位置
int lua_Node_setPosition(lua_State *L);

// 获取位置
int lua_Node_getPosition(lua_State *L);

// 移除
int lua_Node_remove(lua_State *L);

// 元表的方法
static const luaL_Reg lua_Node_Mt_Fun[] = {
    {"setPosition", lua_Node_setPosition},
    {"getPosition", lua_Node_getPosition},
    {"remove", lua_Node_remove},
    {NULL, NULL}
};

// 模块提供的接口
static const luaL_Reg lua_Node_Md_Fun[] = {
    {"create", lua_Node_create},
    {NULL, NULL}
};

// 模块注册
int lua_Node_Md_register(lua_State *L);

// 模块
static const luaL_Reg lua_Node_Md[] = {
    {"Node", lua_Node_Md_register},
    {NULL, NULL}
};

// 表查找函数
int lua_Node_Mt_index(lua_State *L);

void lua_Node_open(lua_State *L);
#endif