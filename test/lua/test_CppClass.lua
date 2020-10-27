

local refObj = Ref.create()

refObj:retain()

print(refObj:getRefCount())

refObj:release()

print(refObj:getRefCount())
