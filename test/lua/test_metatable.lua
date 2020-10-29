
-- 一个新建的表是没有对应的元表的
-- t = {}
-- print(getmetatable((t)))


-- -- 定义一个集合
-- Set = {}
-- -- 元表
-- local mt = {}

-- -- 新建一个集合
-- function Set.new(params)
--     local set = {}
--     setmetatable(set, mt)
--     for _, v in ipairs(params) do
--         set[v] = true
--     end
--     return set
-- end

-- -- 并集
-- function Set.union(set1, set2)
--     local res = Set.new({})
--     for k, v in pairs(set1) do
--         res[k] = v
--     end
--     for k, v in pairs(set2) do
--         res[k] = v
--     end
--     return res
-- end

-- -- 交集
-- function Set.intersection(set1, set2)
--     local res = Set.new({})
--     for k, v in pairs(set1) do
--         res[k] = set2[k]
--     end
--     return res
-- end

-- -- 转换为字符串
-- function Set.tostring(set)
--     local l = {}
--     for k, v in pairs(set) do
--        l[#l + 1] = k 
--     end
--     return "{"..table.concat( l, ", " ).."}"
-- end

-- -- 连接两个表
-- function Set.concat(set1, set2)
--     local res = set1+set2
--     return res
-- end

-- -- 打印函数
-- function Set.print(set)
--     print(Set.tostring(set))
-- end

-- -- 测试打印函数
-- local set = Set.new({1, 2, 3})
-- Set.print(set)

-- -- 测试拥有共同元表
-- local set1 = Set.new({"小米", "米神", "流米", 2})
-- print(getmetatable(set))
-- print(getmetatable(set1))

-- -- 设置元表元方法
-- mt.__add = Set.union
-- mt.__mul = Set.intersection
-- mt.__concat = Set.concat
-- mt.__tostring = Set.tostring

-- print(set+set1)
-- print(set*set1)
-- print(set..set1)

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
    return Person[key]
end
setmetatable(miShen, Person)
-- 打印结果发现即使miShen并没有name这个字段 但是会调用元表的方法
print(miShen.name)
print(miShen:getName())



