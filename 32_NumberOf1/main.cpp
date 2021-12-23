#include <iostream>

using namespace std;

int NumberOf1(unsigned int n) {
    int number = 0;
    while (n) {
        if (n % 10 == 1)
            number ++;
        n = n / 10;
    }
    return number;
}

int NumberOf1Between1AndN(unsigned int n) {
    int number = 0;
    for (unsigned int i = 1; i <= n; ++i)
        number += NumberOf1(i);
    return number;
}

void test() {
    int num = NumberOf1Between1AndN(21345);
    cout << num << endl;
}

int main()
{
    test();
    return 0;
}
