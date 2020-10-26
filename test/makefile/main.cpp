
#include <iostream>
#include "hello.h"

using namespace std;

int main(int argc, char **argv)
{
    int ret = add(10, 20);
    cout << ret << endl;
    cout << "hello world" << endl;
    return 0;
}