#include <iostream>

using namespace std;

//Fibonacci的值可能很大
long long Fibonacci(unsigned n) {
    int result[2] = {0,1};
    if (n < 2)
        return result[n];
    //从下往上计算，首先根据f（0）和f（1）算出f（2），再根据f（1）和f（2）算出f（3）……依此类推就可以算出第n项了。很容易理解，这种思路的时间复杂度是O（n）
    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    for (unsigned int i = 2;i <= n;++i) {
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    return fibN;
}

void test() {
    //功能测试（如输入3、5、10等）。
    long long result = Fibonacci(3);
    cout << result << endl;

    long long result1 = Fibonacci(5);
    cout << result1 << endl;

    long long result2 = Fibonacci(10);
    cout << result2 << endl;
}

void test1() {
    //边界值测试（如输入0、1、2）
    long long result = Fibonacci(0);
    cout << result << endl;

    long long result1 = Fibonacci(1);
    cout << result1 << endl;

    long long result2 = Fibonacci(2);
    cout << result2 << endl;
}

void test2() {
    //性能测试（输入较大的数字，如40、50、100等）。
    long long result = Fibonacci(40);
    cout << result << endl;

    long long result1 = Fibonacci(50);
    cout << result1 << endl;

    long long result2 = Fibonacci(100);
    cout << result2 << endl;
}

int main()
{
    test();
    test1();
    test2();
    return 0;
}
