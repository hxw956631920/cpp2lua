


local node = Node.create()

node:setPosition(10, 20)
print(node:getPosition().x)
print(node:getPosition().y)

print(node:getRefCount())
node:retain()
print(node:getRefCount())