

local refObj = Ref.create()

Ref.retain(refObj)

print(Ref.getRefCount(refObj))

Ref.release(refObj)

print(Ref.getRefCount(refObj))
