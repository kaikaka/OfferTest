#include <iostream>

using namespace std;

bool FindNumbersWith(int data[],int length,int sum,int *num1,int *num2) {
    bool found = false;
    if (length < 1 || num1 == nullptr || num2 == nullptr)
        return found;
    //较大的数字的下标
    int aHead = length - 1;
    //较小的数字的下标
    int behind = 0;
    while (aHead > behind) {
        long long curSum = data[aHead] + data[behind];
        if (curSum == sum) {
            *num1 = data[behind];
            *num2 = data[aHead];
            found = true;
            break;
        }
        else if (curSum > sum)
            aHead --;
        else
            behind ++;
    }
    return found;
}

void test() {
//功能测试（数组中存在和为s的两个数，数组中不存在和为s的两个数）
    int array[] = {1,2,4,7,11,15};
    int num1,num2 = 0;
    bool isFound = FindNumbersWith(array,6,15,&num1,&num2);
    cout << isFound << " " << num1 << " " << num2 << endl;
}

int main()
{
    test();
    return 0;
}
