local colorFont = FontAttribute.setFontColor

local prefix, title

prefix = colorFont("lua端测试用例1:")
title  = colorFont("使用cpp中以模块形式导入的函数", FontAttribute.FC_PURPLE)
print(prefix..title)

a = 50
b = 12.5
print("mylib.add result:", mylib.add(a, b))