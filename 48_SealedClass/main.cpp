#include <iostream>

using namespace std;

template <typename  T> class MakeSealed {
    friend T;
private:
    MakeSealed() {}
    ~MakeSealed() {}
};

class SealedClass: virtual public MakeSealed<SealedClass> {
public:
    SealedClass() {}
    ~SealedClass() {}
};

//虚继承 + 友元类 无法被继承

class Try:public SealedClass {
public:
    Try() {}
    ~Try() {}
};

int main()
{
    return 0;
}
