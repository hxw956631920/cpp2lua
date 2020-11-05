


#include "debugTool.h"

void stackDump(lua_State *L)
{
    int i;
    int top = lua_gettop(L);
    cout << "top num:" << top << endl;
    for (int i = 1; i <= top; i++)
    {
        int type = lua_type(L, i);
        switch (type)
        {
        case LUA_TSTRING:
            cout << lua_typename(L, type) << ":" << lua_tostring(L, i) <<endl;
            break;
        case LUA_TBOOLEAN:
            cout << lua_typename(L, type) << ":" << lua_toboolean(L, i) << endl;
            break;
        case LUA_TNUMBER:
            cout << lua_typename(L, type) << ":" << lua_tonumber(L, i) << endl;
            break;
        default:
            cout << lua_typename(L, type) << endl;
            break;
        }
    }
}
