#include <iostream>

using namespace std;

bool isUgly(int number) {
    while (number % 2 == 0) {
        number /= 2;
    }
    while (number % 3 == 0) {
        number /= 3;
    }
    while (number % 5 == 0) {
        number /= 5;
    }
    return (number == 1) ? true : false;
}

int GetUglyNumber(int index) {
    if (index <= 0)
        return 0;
    int number = 0;
    int uglyFound = 0;
    while (uglyFound < index) {
        ++number;
        if (isUgly(number))
            ++uglyFound;
    }
    return number;
}

void test() {
    int m = GetUglyNumber(150);
    cout << m << endl;
}

int main()
{
    test();
    return 0;
}
