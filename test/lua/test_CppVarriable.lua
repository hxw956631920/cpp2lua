
local colorFont = FontAttribute.setFontColor

local prefix, title, subPrefix, subTitle

prefix = colorFont("lua端测试用例1:")
title  = colorFont("测试cpp端的普通变量", 35)
print(prefix..title)
print("姓名:", name)
print("年龄:", age)
print("职业:", professional)
print("是否gay:", isGay)
print("\n")

prefix = colorFont("lua端测试用例2:")
title  = colorFont("测试cpp端的表", 35)
print(prefix..title)
subPrefix = colorFont("方法1:", 33)
subTitle  = colorFont("常规表", 31)
print(subPrefix..subTitle)
print("姓名:", miShen.name)
print("年龄:", miShen.age)
print("职业:", miShen.professional)
print("是否gay:", miShen.isGay)
print("\n")

subPrefix  = colorFont("方法2:", 33)
subTitle  = colorFont("以number作为key值", 31)
print(subPrefix..subTitle)
print("1:", Person[1])
print("是米神吗", Person[miShen])
print("是否gay", Person.isGay)
print("\n")

subTitle  = colorFont("方法3", 33)
subTitle  = colorFont("以table作为key值", 31)
print(subPrefix..subTitle)
local person = Race.terran
print("人族:", person)
print("姓名", person.name)
print("年龄", person.age)
print("职业", person.professional)
print("是否gay", person.isGay)
print("\n")