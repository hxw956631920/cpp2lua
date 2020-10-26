
#ifndef __REF_H_
#define __REF_H_

#include <iostream>

using namespace std;

class Ref
{
public:
    Ref();
    void retain();
    void release();
    // 获取引用计数
    int getRefCount();
protected:
    // 引用计数
    int _refCount;
};

#endif