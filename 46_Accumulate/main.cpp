#include <iostream>

using namespace std;

//构造函数
class Temp {
private:
    static unsigned int N;
    static unsigned int Sum;
public:
    Temp() { ++ N; Sum += N;}
    static void Reset() {N = 0;Sum = 0;}
    static unsigned int GetSum() { return Sum;}
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n) {
    Temp::Reset();
    Temp *a = new Temp[n];
    delete [] a;
    a = nullptr;
    return Temp::GetSum();
}

//虚函数

class A;
A* Array[2];
class A {
public:
    virtual unsigned int Sum(unsigned int n) {
        return 0;
    }
};

class B: public A {
public:
    virtual unsigned int Sum(unsigned int n) {
        return Array[!!n]->Sum(n-1) + n;
    }
};

int Sum_solution2(int n) {
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;
    int value = Array[1]->Sum(n);
    return value;
}

//函数指针

typedef unsigned int (*fun)(unsigned int) ;

unsigned int Solution3_Teminator(unsigned int n) {
    return 0;
}
unsigned int Sum_Solution3(unsigned int n) {
    static fun f[2] = {Solution3_Teminator,Sum_Solution3};
    return n + f[!!n](n-1);
}

//模板类型

template<unsigned int n> struct Sum_Solution4 {
    enum Value{ N = Sum_Solution4<n - 1>::N + n};
};

template <> struct Sum_Solution4<1> {
    enum Value{ N = 1};
};

void test() {
    unsigned int a = Sum_Solution1(6);
    cout << a << endl;

    int b = Sum_solution2(6);
    cout << b << endl;

    unsigned int c = Sum_Solution3(6);
    cout << c << endl;

}


int main()
{
    test();
    return 0;
}
