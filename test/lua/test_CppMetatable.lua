

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

print(miShen.dd)