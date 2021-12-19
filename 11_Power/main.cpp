#include <iostream>

using namespace std;

double PowerWithUnsignedExponent (double base, unsigned int exponent) {

    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    double result = PowerWithUnsignedExponent(base,exponent >> 1);
    result *= result;
    //奇数
    if ((exponent & 0x1) == 1)
        result *= base;
    return result;
}

void test() {
    cout << PowerWithUnsignedExponent(10,2) << endl;
    //底数指数为负数
    cout << PowerWithUnsignedExponent(10,-2) << endl;
    cout << PowerWithUnsignedExponent(-10,2) << endl;
    //底数指数为0
    cout << PowerWithUnsignedExponent(0,0) << endl;

}

int main()
{
    test();
    return 0;
}
