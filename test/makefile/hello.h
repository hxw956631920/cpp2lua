
#ifndef __HELLO_H_
#define __HELLO_H_

extern "C"
{
    // lua标准库
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

int add(int x, int y);

#endif