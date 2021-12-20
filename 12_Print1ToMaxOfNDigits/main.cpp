#include <iostream>

using namespace std;

//递归实现

void PrintNumber(char *number) {
    //取消打印补0
    bool isBeginning0 = true;
    int nLength = strlen(number);
    for (int i = 0; i< nLength; ++ i) {
        if (isBeginning0 && number[i] != '0') {
            isBeginning0 = false;
        }
        if (!isBeginning0) {
            printf("%c",number[i]);
        }
    }
    printf("\t");
}

void Print1ToMaxOfNDigitsRecursively(char * number,int length,int index) {
    //长度与索引相等开始打印
    if (index == length - 1) {
        PrintNumber(number);
        return;
    }
    for (int i = 0;i< 10;++i) {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number,length,index + 1);
    }
}

void PrintToMaxOfNDigits(int n) {
    if (n <= 0) return;
    char * number = new char [n + 1];
    //下标从0开始
    number[n] = '\0';
    for (int i = 0;i < 10; ++i) {
        number[0] = i + '0';//字符转数字 利用数字在ASCII中与0的相对位置
        Print1ToMaxOfNDigitsRecursively(number,n,0);
    }
    delete [] number;
}

void test() {
    //功能测试（输入1、2、3……）
    PrintToMaxOfNDigits(2);
    //特殊输入测试（输入-1、0）
    PrintToMaxOfNDigits(-1);
    PrintToMaxOfNDigits(0);
}

int main()
{
    test();
    return 0;
}
