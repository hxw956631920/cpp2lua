
local colorFont = FontAttribute.setFontColor

local prefix, title

prefix = colorFont("lua端测试用例1:")
title  = colorFont("使用cpp中的函数", FontAttribute.FC_PURPLE)
print(prefix..title)
a = 10
b = 20
print("add result:", add(a, b))