#include <iostream>

using namespace std;

int GetLastK(int * data,int length,int k,int start,int end) {
    if (start > end)
        return -1;
    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];
    if (middleData == k) {
        if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length -1)
            return middleIndex;
        else
            start = middleIndex + 1;
    } else if (middleData < k) //在后半段
        start = middleIndex + 1;
    else
        end = middleIndex - 1;
    return GetLastK(data,length,k,start,end);
}

int GetFirstK(int * data,int length,int k,int start,int end) {
    if (start > end)
        return -1;
    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];
    if (middleData == k) {
        if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
            return middleIndex;
        else
            end = middleIndex - 1;
    } else if (middleData > k) //在前半段
        end = middleIndex - 1;
    else
        start = middleIndex + 1;
    return GetFirstK(data,length,k,start,end);
}

int GetNumberOfK(int * data,int length,int k) {
    int number = 0;
    if (data != nullptr && length > 0) {
        int first = GetFirstK(data,length,k,0,length - 1);
        int last = GetLastK(data,length,k,0,length - 1);
        if (first > -1 && last > -1)
            number = last - first + 1;
    }
    return number;
}

void test() {
    //功能测试（数组中包含查找的数字，数组中没有查找的数字，查找的数字在数组中出现一次/多次）。
    int test1[] = {1,2,3,3,3,3,4,5};
    int t1 = GetNumberOfK(test1,8,1);
    cout << t1 << endl;

    int t2 = GetNumberOfK(test1,8,7);
    cout << t2 << endl;

    int t3 = GetNumberOfK(test1,8,3);
    cout << t3 << endl;

}

int main()
{
    test();
    return 0;
}
