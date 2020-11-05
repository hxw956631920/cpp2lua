
local colorFont = FontAttribute.setFontColor

local prefix, title

prefix = colorFont("lua端测试用例1:")
title  = colorFont("以面向对象形式注册的c++对象", FontAttribute.FC_PURPLE)

local refObj = Ref.create()

refObj:retain()

print(refObj:getRefCount())

refObj:release()

print(refObj:getRefCount())
