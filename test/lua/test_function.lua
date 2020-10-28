
function add(a, b)
    return a+b
end

Person = {
    _name = "Xiaomi",
    _age  = 26,
    _isGay = true
}

function Person:getName()
    if self._name then
        return self._name
    end
end

function Person:setName(name)
    self._name = name
end

function Person:getAge()
    if self._age then
        return self._age
    end
end

function Person:setAge(age)
    self._age = age
end

function Person:getIsGay()
    if self._isGay then
        return self._isGay
    end
end

function Person:setIsGay(isGay)
    self._isGay = isGay
end

function Person:print()
    print("name", self._name)
    print("age:", self._age)
    print("isGay", self._isGay)
end