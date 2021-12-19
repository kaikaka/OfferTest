#include <iostream>

using namespace std;

int NumberOf1(int n) {
    int count = 0;
    // 直到n = 0
    while (n) {
        ++count;
        //&
        n = (n - 1) & n;
//        cout << n << endl;
    }

    return count;
}

void test() {
    //正数（包括边界值1、0x7FFFFFFF）。
    cout << NumberOf1(1) << endl;
    cout << NumberOf1(12) << endl;
    cout << NumberOf1(2147483647) << endl;

    //负数（包括边界值0x80000000、0xFFFFFFFF）。
    cout << NumberOf1(-2147483648) << endl;
    cout << NumberOf1(-1) << endl;
    //0
    cout << NumberOf1(0) << endl;
}

int main()
{
    test();
    return 0;
}
