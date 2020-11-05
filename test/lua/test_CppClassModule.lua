
local colorFont = FontAttribute.setFontColor

local prefix, title

prefix = colorFont("lua端测试用例1:")
title  = colorFont("以模块形式注册的c++对象", FontAttribute.FC_PURPLE)
print(prefix..title)

local refObj = Ref.create()
refObj.retain()

Ref.retain(refObj)

print("retain后,refObj:getRefCount()", Ref.getRefCount(refObj))

Ref.release(refObj)

print("release后,refObj:getRefCount()", Ref.getRefCount(refObj))
