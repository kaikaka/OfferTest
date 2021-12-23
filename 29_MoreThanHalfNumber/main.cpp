#include <iostream>

using namespace std;

bool g_bInputInvalid = false;
bool CheckInvalidArray(int * numbers,int length) {
    g_bInputInvalid = false;
    if (numbers == nullptr && length <= 0)
        g_bInputInvalid = true;
    return g_bInputInvalid;
}

//出现次数是否大于数组的一半
bool CheckMoreThanHalf(int *numbers,int length,int number) {
    int times = 0;
    //计算number出现的次数
    for (int i = 0;i < length ;++ i) {
        if (numbers[i] == number)
            times++;
    }
    bool isMoreThanHalf = true;
    if (times * 2 <= length) {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }
    return isMoreThanHalf;
}

int MoreThanHalfNum(int * numbers,int length) {
    if (CheckInvalidArray(numbers,length))
        return 0;
    int result = numbers[0];
    int times = 1;
    for (int i = 1;i < length; ++ i) {
        if (times == 0) {
            result = numbers[i];
            times = 1;
        } else if (numbers[i] == result)
            times++;
        else
            times--;
    }
    if (!CheckMoreThanHalf(numbers,length,result))
        result = 0;
    return result;
}

void test() {
    //功能测试（输入的数组中存在一个出现次数超过数组长度一半的数字，输入的数组中不存在一个出现次数超过数组长度一半的数字）。
    int array[] = {1,2,3,2,2,2,5,4,2};
    int num = MoreThanHalfNum(array,9);
    cout << num << endl;

    int array1[] = {1,2,3,2,5,4,2};
    int num1 = MoreThanHalfNum(array1,7);
    cout << num1 << endl;

    int array2[] = {1};
    int num2 = MoreThanHalfNum(array2,7);
    cout << num2 << endl;
}

int main()
{
    test();
    return 0;
}
