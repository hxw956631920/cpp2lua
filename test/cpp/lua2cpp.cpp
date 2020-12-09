
#include "lua2cpp.h"
// 测试lua中的基本数据类型
void test_varriable(lua_State *L)
{
    // 字符串
    lua_getglobal(L, "name");
    if (lua_isstring(L, -1))
    {
        string prefix = setFontColor("Cpp端测试用例1:");
        string title  = setFontColor("c++读取lua字符串", FC_PURPLE);
        cout << prefix + title << endl;
        std::cout << lua_tostring(L, -1) << endl;   
    }
    // 数字
    lua_getglobal(L, "age");
    if (lua_isnumber(L, -1))
    {
        string prefix = setFontColor("Cpp端测试用例2:");
        string title  = setFontColor("c++读取lua数字", FC_PURPLE);
        cout << prefix + title << endl;
        std::cout << lua_tonumber(L, -1) << endl;   
    }
    // bool
    lua_getglobal(L, "isGay");
    if (lua_isboolean(L, -1))
    {
        string prefix = setFontColor("Cpp端测试用例3:");
        string title  = setFontColor("c++读取lua布尔", FC_PURPLE);
        cout << prefix + title << endl;
        std::cout << lua_toboolean(L, -1) << endl;   
    }
    // 表 写法1
    // 将表person放置到栈顶
    lua_getglobal(L, "person");
    // 压入age 此时 age在栈顶 索引为-1 person 索引为-2
    lua_pushstring(L, "age");
    // 以栈顶为key(也就是age)对位于栈-2位置的表中查找该key对应的value 然后将key出栈
    // 对应的value进栈 此时 26(age对应的值)在栈顶 person的索引为-2
    lua_gettable(L, -2);
    if (lua_isinteger(L, -1))
    {
        string prefix = setFontColor("Cpp端测试用例4:");
        string title  = setFontColor("c++读取lua表,写法1", FC_PURPLE);
        cout << prefix + title << endl;
        std::cout << "person.age:" << lua_tointeger(L, -1) << endl;   
    }
    // 将name压入栈 此时栈数据顺序为  -1:name -2:26 -3:person
    lua_pushstring(L, "name");
    lua_gettable(L, -3);
    if (lua_isstring(L, -1))
    {
        std::cout << "person.name:" << lua_tostring(L, -1) << endl;   
    }
    lua_pushstring(L, "isGay");
    lua_gettable(L, -4);
    if (lua_isboolean(L, -1))
    {
        std::cout << "person.isGay:" << lua_toboolean(L, -1) << endl;   
    }

    // 表 写法2
    // lua_getglobal(L, "person");
    // 函数原型 lua_getfield(lua_State *L, int index, const char *k);
    // 将index处的值以k为索引查找对应的value(如果index处的不是表就会报错)并压入栈顶
    // 将位于-4处的person以age为k进行查找对应的value压入栈顶
    lua_getfield(L, -4, "age");
    if (lua_isinteger(L, -1))
    {
        string prefix = setFontColor("Cpp端测试用例4:");
        string title  = setFontColor("c++读取lua表,写法2", FC_PURPLE);
        cout << prefix + title << endl;
        std::cout << "age:" << lua_tointeger(L, -1) << endl;  
    }
}

// 测试cpp调用lua中的function
void test_function(lua_State *L)
{
    int ret;
    // 调用lua中定义的全局函数
    string prefix = setFontColor("Cpp端测试用例1:");
    string title  = setFontColor("c++读取lua函数", FC_PURPLE);
    cout << prefix + title << endl;
    lua_getglobal(L, "add");
    lua_pushnumber(L, 10);
    lua_pushnumber(L, 20);
    ret = lua_pcall(L, 2, 1, 0);
    if (ret)
    {
        std::cout << "pcall error" << endl;
    }
    if (lua_isnumber(L, -1))
    {
        cout << "result is " << lua_tonumber(L, -1) << endl;
    }
    
    // 调用某个表中的函数
    prefix = setFontColor("Cpp端测试用例2:");
    title  = setFontColor("c++读取lua表的函数", FC_PURPLE);
    cout << prefix + title << endl;
    lua_getglobal(L, "Person");
    lua_getfield(L, -1, "getName");
    //c++通过栈调用某个表的函数可以认为是.调用，因为需要把对象传进去，因此这里将Person作为副本压入栈中，作为第一个参数
    lua_pushvalue(L, -2);
    ret = lua_pcall(L, 1, 1, 0);
    if (lua_isstring(L, -1))
    {
        std::cout << "Person.getName:" << lua_tostring(L, -1) << endl;
    }
    // 将栈顶的Xiaomi移除
    lua_remove(L, -1);
    // 查找setName函数放置于栈顶
    lua_getfield(L, -1, "setName");
    // 将Person拷贝一份放置于栈顶
    lua_pushvalue(L, -2);
    // 压入要设置的新名字
    lua_pushstring(L, "baldwey");
    // 调用函数
    ret = lua_pcall(L, 2, 0, 0);
    // 获取print函数
    lua_getfield(L, -1, "print");
    lua_pushvalue(L, -2);
    // 执行print
    ret = lua_pcall(L, 1, 0, 0);
}

// 测试lua中的require
void test_require(lua_State *L)
{
    int ret;
    string prefix, title, subTitle;
    prefix = setFontColor("Cpp端测试用例1:");
    title  = setFontColor("c++读取lua中require返回的对象:", FC_PURPLE);
    subTitle = setFontColor("写法1:", FC_BROWN);
    cout << prefix + title << endl;
    cout << subTitle << endl;
    // 写法1
    lua_getglobal(L, "lib");
    lua_getfield(L, -1, "_name");
    if (lua_isstring(L, -1))
    {
        std::cout << "lib._name:" << lua_tostring(L, -1) << endl;   
    }

    lua_getglobal(L, "lib");
    lua_getfield(L, -1, "sex");
    if (lua_isstring(L, -1))
    {
        std::cout << "lib.sex:" << lua_tostring(L, -1) << endl;   
    }
    // 写法2
    subTitle = setFontColor("写法2:", FC_BROWN);
    cout << subTitle << endl;
    lua_getglobal(L, "lib");
    lua_getfield(L, -1, "_name");
    if (lua_isstring(L, -1))
    {
        std::cout << "lib._name:" << lua_tostring(L, -1) << endl;   
    }

    lua_getfield(L, -2, "sex");
    if (lua_isstring(L, -1))
    {
        std::cout << "lib.sex:" << lua_tostring(L, -1) << endl;   
    }
    // 写法3
    subTitle = setFontColor("写法2:", FC_BROWN);
    cout << subTitle << endl;
    lua_getglobal(L, "lib");
    lua_pushstring(L, "_name");
    lua_gettable(L, -2);
    if (lua_isstring(L, -1))
    {
        std::cout << "lib._name:" << lua_tostring(L, -1) << endl;   
    }

    lua_pushstring(L, "sex");
    lua_gettable(L, -3);
    if (lua_isstring(L, -1))
    {
        std::cout << "lib.sex:"  << lua_tostring(L, -1) << endl;   
    }
}

// 测试lua中的元表
void test_metatable(lua_State *L)
{
    string prefix, title, content;
    // 获取表-miShen
    prefix = setFontColor("cpp端测试用例1:", FC_BLUE);
    title = setFontColor("获取表的元表，并查看该元表name字段的值", FC_PURPLE);
    std::cout << prefix+title << endl;
    lua_getglobal(L, "miShen");
    lua_pushstring(L, NULL);
    lua_setfield(L, -2, "name");
    // 获取miShen的元表 
    lua_getmetatable(L, -1);//-3
    lua_getfield(L, -1, "name");
    if (lua_isstring(L, -1))
    {
        std::cout << "miShen's metatable's name:" << lua_tostring(L, -1) << endl;//-2
    }

    // 更改Person的默认名字
    prefix = setFontColor("cpp端测试用例2:", FC_BLUE);
    title = setFontColor("更改元表name字段的值，调用元表的getName但是传的是表的结果", FC_PURPLE);
    std::cout << prefix+title << endl;
    lua_pushstring(L, "baldwey");
    lua_setfield(L, -3, "name");
    // 调用person的getName函数 但是传的对象是miShen
    lua_getfield(L, -2, "getName");
    lua_pushvalue(L, -4);
    int ret = lua_pcall(L, 1, 1, 0);
    if (lua_isstring(L, -1))
    {
        std::cout << "miShen's getName(miShen):" << lua_tostring(L, -1) << endl;//-1
    }

    prefix = setFontColor("cpp端测试用例3:", FC_BLUE);
    title = setFontColor("调用元表的getName传的是元表的结果", FC_PURPLE);
    std::cout << prefix+title << endl;
    lua_getfield(L, -3, "getName");
    lua_pushvalue(L, -4);
    ret = lua_pcall(L, 1, 1, 0);
    if (lua_isstring(L, -1))
    {
        std::cout << "miShen's getName(Person):" << lua_tostring(L, -1) << endl;
    }
}

// 测试lua调用cpp的变量
void test_cppVarriable(lua_State *L)
{
    // 普通变量
    lua_pushstring(L, "小米");
    lua_setglobal(L, "name");
    lua_pushnumber(L, 26);
    lua_setglobal(L, "age");
    lua_pushstring(L, "卖屁股的");
    lua_setglobal(L, "professional");
    lua_pushboolean(L, 1);
    lua_setglobal(L, "isGay");
    // 表 创建方法一
    // 创建空表 并将该表压如栈顶
    lua_newtable(L);
    // lua_newtable 等价于 如下
    // lua_createtable(lua_State *L, int narr, int nrec);
    // 预分配narr个array元素的空间和nrec个非array元素的空间
    // lua_createtable(L, 0, 0);
    // 压入value值
    lua_pushstring(L, "小米");
    // 对于栈中-2的值找到其key为name，将对应的value设置为栈顶的值 也就是"小米"
    lua_setfield(L, -2, "name");
    lua_pushnumber(L, 26);
    lua_setfield(L, -2, "age");
    lua_pushstring(L, "卖屁股的");
    lua_setfield(L, -2, "professional");
    lua_pushboolean(L, 1);
    lua_setfield(L, -2, "isGay");
    // 给位于栈顶的值取一个名字 由于现在位于栈顶的是表 因此给表取名为person
    lua_setglobal(L, "miShen");

    // 表 创建方法二
    lua_createtable(L, 0, 0);
    // key值入栈
    lua_pushnumber(L, 1);
    // value值入栈
    lua_pushnumber(L, 25);
    lua_settable(L, -3);
    // 将miShen作为key
    lua_getglobal(L, "miShen");
    lua_pushboolean(L, 1);
    lua_settable(L, -3);
    // 给表取名
    lua_setglobal(L, "Person");

    // 表 创建方法三
    lua_createtable(L, 0, 0);
    lua_pushstring(L, "terran");
    // 将miShen作为value
    lua_getglobal(L, "miShen");
    lua_rawset(L, -3);
    lua_setglobal(L, "Race");
}

// __index元方法
int indexMethod(lua_State *L)
{
    int argc = lua_gettop(L);
    if (argc == 2)
    {
        if (lua_istable(L, -2))
        {
            // 获取到目标表的元表
            lua_getmetatable(L, -2);
            // 查询元表key对应的value
            lua_getfield(L, -1, lua_tostring(L, -2));
        }
    }
    return 1;
}

// __newIndex元方法
int newindexMethod(lua_State *L)
{
    return 1;
}

// 测试lua调用cpp创建的表和为表设置元表
void test_cppMetatable(lua_State *L)
{
    // 新建一个表
    lua_newtable(L);
    lua_pushstring(L, "小米");
    lua_setfield(L, -2, "name");
    // 为表设置一个函数
    lua_pushcfunction(L, pkgAdd);
    lua_setfield(L, -2, "add");

    // 为该表设置元表
    lua_newtable(L);
    lua_pushinteger(L, 25);
    lua_setfield(L, -2, "age");
    // 设置__index字段
    // 第一种是对__index赋值一个方法 该方法将表的元表key对应的value返回
    lua_pushcfunction(L, indexMethod);
    // 第二种是直接对__index赋值一个表 将访问这个表key对应的value
    // lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    // 设置__newindex字段
    lua_pushcfunction(L, newindexMethod);
    lua_setfield(L, -2, "__newindex");

    // setmetatable在api中的原型;
    int t = lua_type(L, 2);
    luaL_argcheck(L, t == LUA_TNIL || t == LUA_TTABLE, 2, "nil or table expected");
    lua_settop(L, 2);
    // lua_setmetatable 将栈顶table弹出， 设置为-2位置的table的元表
    lua_setmetatable(L, 1);
    lua_setglobal(L, "miShen");
}

int add(int a, int b)
{
    int c = a + b;
    return c;
}

// 测试lua调用cpp的函数
void test_cppFunction(lua_State *L)
{
    // 注册函数
    lua_register(L, "add", pkgAdd);
}

double add(double x, double y)
{
    return x+y;
}

// 包装的cpp函数
int pkgAdd(lua_State *L)
{
    int num = lua_gettop(L);
    if (num == 2)
    {
        double number1, number2;
        if (lua_isnumber(L, 1) && lua_isnumber(L, 2))
        {
            number1 = lua_tonumber(L, 1);
            number2 = lua_tonumber(L, 2);
            double result = add(number1, number2);
            lua_pushnumber(L, result);
        }
    }
    return 1;
}

int lua_openmylib(lua_State *L)
{
    // 创建新的表将所有函数放在这个表中
    luaL_newlib(L, mylibs_funcs);
    // 等价于如下写法
    // luaL_newlibtable(L, mylibs_funcs);
    // luaL_setfuncs(L, mylibs_funcs, 0);

    // 也等价于如下写法
    // lua_createtable(L, 0, sizeof(mylibs_funcs)/sizeof(mylibs_funcs[0]) - 1);
    // luaL_setfuncs(L, mylibs_funcs, 0);

    // luaL_setfuncs的原型如下
/*   
    luaL_checkstack(L, nup, "too many upvalues");
    for (; l->name != NULL; l++) {  
        int i;
        for (i = 0; i < nup; i++)  
        // 这里的lua_pushvalue实际上是设置函数所在环境的upvalue 
        lua_pushvalue(L, -nup);
        lua_pushcclosure(L, l->func, nup);  
        lua_setfield(L, -(nup + 2), l->name);
    }
    lua_pop(L, nup);  
*/
    // 实际上没必要这样写
    // 某个模块的库函数 我们一般而言是没有upvalue的 因此没必要这么麻烦 直接创建一个表并且压入一个函数
    // 再对这个表设置该函数的索引就好了
    return 1;
}

// 测试采用模块包装函数
void test_cppModuleFunction(lua_State *L)
{
    const luaL_Reg *lib = lua_reg_libs;
    for (; lib->func; lib++)
    {
        luaL_requiref(L, lib->name, lib->func, 1);
        // 移除该模块
        lua_pop(L, 1);
    }
}

// 测试cpp类注册为模块形式
void test_cppClassModule(lua_State *L)
{
    // 基础lua库
    luaL_openlibs(L);
    // 基础类注册
    lua_baseClass_open_module(L);
}

// 测试cpp类以面向对象形式注册
void test_cppClassOOP(lua_State *L)
{
    // 基础lua库
    luaL_openlibs(L);
    // 基础类注册
    lua_baseClass_open_oop(L);
}

// 测试cpp类继承
void test_cppInheritance(lua_State *L)
{
    // 基础lua库
    luaL_openlibs(L);
    // ref注册
    lua_baseClass_open_oop(L);
    // node类注册
    lua_Node_open(L);
}
