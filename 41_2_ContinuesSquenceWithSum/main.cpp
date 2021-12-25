#include <iostream>

using namespace std;

void PrintContinuousSequence(int small,int big) {
    for (int i = small;i <= big; ++ i)
        cout << i << "\n" << endl;
    cout << "-----" << endl;
}

void FindContinuousSequence(int sum) {
    if (sum < 3) return;
    int small = 1;
    int big = 2;
    int middle = (sum + 1) / 2;
    int curSum = small + big;
    while (small < middle) {
        if (curSum == sum)
            PrintContinuousSequence(small,big);

        while (curSum > sum && small < middle) {
            curSum -= small;
            small ++;
            if (curSum == sum)
                PrintContinuousSequence(small,big);
        }
        big ++;
        curSum += big;
    }
}

void test() {
    FindContinuousSequence(9);
}

int main()
{
    test();
    return 0;
}
