#include <iostream>

using namespace std;

int MinInOrder(const int * numbers,int index1,int index2) {
    int result = numbers[index1];
    for(int i = index1 + 1;i <= index2;i ++) {
        if (result > numbers[i])
            result = numbers[i];
    }
    return result;
}

int min(const int * numbers,int length) {
    if (numbers == NULL || length <= 0) {
        return -1;
//        throw new std::exception();
    }
    //索引1
    int index1 = 0;
    //索引2
    int index2 = length - 1;
    int indexMid = index1;
    //递增数组中，旋转后的数组，numbers[index1] 必然大于等于 numbers[index2] 所以退出循环的条件是index2 - index1 == 1
    while (numbers[index1] >= numbers[index2]) {

        if(index2 - index1 == 1) {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;
        //如果下标为index1 、index2和indexmid指向的三个数字相等，则只能顺序查找
        if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
            return MinInOrder(numbers,index1,index2);
        if (numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if (numbers[indexMid] <= numbers[index2]) {
            index2 = indexMid;
        }
    }
    return numbers[indexMid];
}

void test() {
    //功能测试（输入的数组是升序排序数组的一个旋转，数组中有重复数字或者没有重复数字）。
    int array[] = {3,4,5,1,2};
    int result = min((int *)array,5);
    cout << result << endl;

    int array1[] = {3,4,5,1,2,2};
    int result1 = min((int *)array,6);
    cout << result1 << endl;
}

void test1() {
//    边界值测试（输入的数组是一个升序排序的数组、只包含一个数字的数组）。
    int array[] = {3,4,5,6,7};
    int result = min((int *)array,5);
    cout << result << endl;

    int array1[] = {3};
    int result1 = min((int *)array,1);
    cout << result1 << endl;

    int result2 = min(NULL,0);
    cout << result2 << endl;
}

int main()
{
    test();
    test1();
    return 0;
}
