
-- 前缀
local prefix
-- 标题
local title

local colorFun = FontAttribute.setFontColor
-- 一个新建的表是没有对应的元表的
t = {}

prefix = colorFun("Lua测试用例1:")
title = colorFun("测试一个新建的表的元表是否为空:", FontAttribute.FC_PURPLE)
print(prefix..title)
print(getmetatable((t)))

-- 定义一个集合
Set = {}
-- 元表
local mt = {}

-- 新建一个集合
function Set.new(params)
    local set = {}
    setmetatable(set, mt)
    for _, v in ipairs(params) do
        set[v] = true
    end
    return set
end

-- 并集
function Set.union(set1, set2)
    local res = Set.new({})
    for k, v in pairs(set1) do
        res[k] = v
    end
    for k, v in pairs(set2) do
        res[k] = v
    end
    return res
end

-- 交集
function Set.intersection(set1, set2)
    local res = Set.new({})
    for k, v in pairs(set1) do
        res[k] = set2[k]
    end
    return res
end

-- 转换为字符串
function Set.tostring(set)
    local l = {}
    for k, v in pairs(set) do
       l[#l + 1] = k 
    end
    return "{"..table.concat( l, ", " ).."}"
end

-- 连接两个表
function Set.concat(set1, set2)
    local res = set1+set2
    return res
end

-- 打印函数
function Set.print(set)
    print(Set.tostring(set))
end

-- 测试打印函数
local set = Set.new({1, 2, 3})

-- 测试拥有共同元表
local set1 = Set.new({"小米", "米神", "流米", 2})
prefix = colorFun("Lua测试用例2:")
title = colorFun("测试两个表拥有的共同元表是否相同", FontAttribute.FC_PURPLE)
print(prefix..title)
print(getmetatable(set))
print(getmetatable(set1))

-- 设置元表元方法
mt.__add = Set.union
mt.__mul = Set.intersection
mt.__concat = Set.concat
mt.__tostring = Set.tostring

prefix = colorFun("Lua测试用例3:")
title = colorFun("测试lua端设置元方法", FontAttribute.FC_PURPLE)
print(prefix..title)
print(set+set1)
print(set*set1)
print(set..set1)

-- 米神
miShen = {}
-- Person 是 miShen的元方法
Person = {
    name = "小米",
    age  = 25,
    isGay = true
}
function Person.getName(t)
    if t.name then
        return t.name
    end
end

Person.__index = function (t, key)
    print("访问key:", key)
    -- 这个打印是用来测试是否走元方法
    print("====走__index元方法===")
    return Person[key]
end

setmetatable(miShen, Person)
-- -- 打印结果发现即使miShen并没有name这个字段 但是会调用元表的方法
-- -- 显示结果为 
-- -- 访问key:	name
-- -- ====走元方法===
-- -- 小米
prefix = colorFun("Lua测试用例4:")
title = colorFun("测试访问表没有的字段是否走元表__index方法", FontAttribute.FC_PURPLE)
print(prefix..title)
print(miShen.name)

-- -- 由于miShen并没有getName这个字段 因此还是调用元方法
-- -- 显示结果为
-- -- 访问key:	getName
-- -- ====走元方法===
-- -- 访问key:	name
-- -- ====走元方法===
-- -- 访问key:	name
-- -- ====走元方法===
print(miShen:getName())

-- 此时设置完了该字段因此不会触发元方法
prefix = colorFun("Lua测试用例5:")
title = colorFun("测试设置了该表的字段后再去访问是否还走元表的__index方法", FontAttribute.FC_PURPLE)
print(prefix..title)
miShen.name = "米神"
print(miShen.name)

-- 测试rawget函数
-- 结果显示直接打印为空 说明没有走元表
prefix = colorFun("Lua测试用例6:")
title = colorFun("测试rawget函数", FontAttribute.FC_PURPLE)
print(prefix..title)
miShen.name = nil
print(rawget(miShen, "name"))


-- 测试__newindex字段
-- __newindex字段是用于table的更新 __index字段用于table的查询
-- 如果对一个表中不存在的索引赋值时，就会执行__newindex方法，如果__newindex存在，则调用该元方法，并且不执行赋值！！！
Person.__newindex = function (t, key)
    print("访问key:", key)
    -- 这个打印是用来测试是否走元方法
    print("====走__newindex元方法===")
end
prefix = colorFun("Lua测试用例7:")
title = colorFun("测试__newindex方法:", FontAttribute.FC_PURPLE)
print(prefix..title)
miShen.name = "米神"
print(miShen.name)

-- 测试rawset
prefix = colorFun("Lua测试用例8:")
title = colorFun("测试rawset:", FontAttribute.FC_PURPLE)
print(prefix..title)
miShen.name = nil
rawset(miShen, "name", "米神")
print(miShen.name)


