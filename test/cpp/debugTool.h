
#ifndef __DEBUGTOOL_H_
#define __DEBUGTOOL_H_

#include "luastd.h"
#include <iostream>

using namespace std;
// 调试用 打印lua栈内容
void stackDump(lua_State *L);

#endif