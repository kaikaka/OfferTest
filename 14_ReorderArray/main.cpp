#include <iostream>

using namespace std;

//是不是偶数
bool isEven(int n) {
    return (n & 1) == 0;
}

void Reorder(int *pData,unsigned int length,bool (*func)(int)) {
    if (pData == NULL || length == 0) return;
    int *pBegin = pData;//相当于头指针
    int *pEnd = pData + length - 1;//尾指针
    while (pBegin < pEnd) {
        //要么pBegin ++ 要么pEnd --
        while (pBegin < pEnd && !func(*pBegin)) {
            pBegin ++;
        }
        while (pBegin < pEnd && func(*pEnd)) {
            pEnd --;
        }
        if (pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

void ReorderOddEven(int *pData,unsigned int length) {
    Reorder(pData,length,isEven);
}

void test() {
    //输入数组中的奇数、偶数交替出现
    int array[6] = {1,2,3,4,5,6};
    ReorderOddEven((int *)array,6);

    for(int i = 0; i< (int)(sizeof (array) / sizeof (array[0]));++i) {
        cout << array[i] << endl;
    }

    cout << "-------------" << endl;
    //输入的数组中所有偶数都出现在奇数的前面
    int array1[6] = {2,4,6,1,3,7};
    ReorderOddEven((int *)array1,6);

    for(int i = 0; i< (int)(sizeof (array1) / sizeof (array1[0]));++i) {
        cout << array1[i] << endl;
    }

    cout << "-------------" << endl;
    //输入的数组中所有奇数都出现在偶数的前面
    int array2[6] = {1,3,7,2,4,6};
    ReorderOddEven((int *)array2,6);

    for(int i = 0; i< (int)(sizeof (array2) / sizeof (array2[0]));++i) {
        cout << array2[i] << endl;
    }

    cout << "-------------" << endl;
    //输入的数组只包含一个数字
    int array3[1] = {1};
    ReorderOddEven((int *)array3,1);

    for(int i = 0; i< (int)(sizeof (array3) / sizeof (array3[0]));++i) {
        cout << array3[i] << endl;
    }
}

int main()
{
    test();
    return 0;
}
