
#include "Ref.h"

Ref::Ref()
:_refCount(1)
{

}

void Ref::retain()
{
    if (_refCount <= 0)
    {
        std::cout << "reference count should greater than 0" << endl;
    }
    ++_refCount;
}

void Ref::release()
{
    if (_refCount <= 0)
    {
        std::cout << "reference count should greater than 0" << endl;
    }
    --_refCount;
    if (_refCount < 0)
    {
        delete this;
    }
    
}

int Ref::getRefCount()
{
    return _refCount;
}