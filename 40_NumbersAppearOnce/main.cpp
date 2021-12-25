#include <iostream>

using namespace std;

unsigned int FindFirstBitIs1(int num) {
    int indexBit = 0;
    //获取1所在的位
    while ((num & 1) == 0 && (indexBit < 8 * sizeof (int))) {
        num = num >> 1;
        ++indexBit;
    }
    return indexBit;
}

//判断当前数对应的位是不是1
bool IsBit1 (int num,unsigned int indexBit) {
    num = num >> indexBit;
    return (num & 1);
}

void FindNumsAppearOnce(int data[],int length,int *num1,int *num2) {
    if (data == nullptr || length < 2)
        return;
    int resultExclusiveOR = 0;
    for (int i = 0;i < length; ++i) {
        resultExclusiveOR ^= data[i];
    }
    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
    *num1 = *num2 = 0;
    for(int j = 0;j < length; ++j) {
        if(IsBit1(data[j],indexOf1))
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }
}

void test() {
    int array[] = {2,4,3,6,3,2,5,5};
    int n1 ,n2 ;
    FindNumsAppearOnce(array,8,&n1,&n2);
    cout << n1 << endl;
    cout << n2 << endl;
}

int main()
{
    test();
    return 0;
}
