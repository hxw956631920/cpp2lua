

local colorFont = FontAttribute.setFontColor

local prefix, title, subPrefix, subTitle

prefix = colorFont("lua端测试用例1:")
title  = colorFont("测试cpp端的表的成员", 35)
print(prefix..title)
print("miShen.name:", miShen.name)

prefix = colorFont("lua端测试用例2:")
title  = colorFont("测试cpp端的表的成员函数", 35)
print(prefix..title)
print("miShen.add() result:", miShen.add(12, 24))

prefix = colorFont("lua端测试用例3:")
title  = colorFont("测试cpp端的元表__index字段", 35)
print(prefix..title)
print("miShen.age:", miShen.age)

prefix = colorFont("lua端测试用例4:")
title  = colorFont("测试cpp端的元表__newindex字段", 35)
print(prefix..title)
miShen.isGay = true
print("miShen.isGay:", miShen.isGay)

