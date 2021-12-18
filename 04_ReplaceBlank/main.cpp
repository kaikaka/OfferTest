#include <iostream>

using namespace std;

//length为字符数组string的总容量
void ReplaceBlank(char string[], int length) {
    if (string == NULL || length <= 0) return;
    //originalLength为字符串string的实际长度
    int originalLength = 0;
    //空格的数量
    int numberOfBlank = 0;
    int i = 0;
    while (string[i] != '\0') {
        ++ originalLength;
        if (string[i] == ' ') {
            ++ numberOfBlank;
        }
        ++ i;
    }
    //newLength为把空格替换为'%20'之后的长度
    int newLength = originalLength + numberOfBlank * 2;
    if (newLength > length) {
        //字符串长度不够
        return;
    }

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
        if (string[indexOfOriginal] == ' ') {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        } else {
            //复制不是空格的字符
            string[indexOfNew--] = string[indexOfOriginal];
        }
        -- indexOfOriginal;
    }
    cout << string << endl;
}

void test() {
//输入的字符串中包含空格（空格位于字符串的最前面，空格位于字符串的最后面，空格位于字符串的中间，字符串中有连续多个空格）。
    char a1[] = "We are happy.";
    ReplaceBlank(a1,30);
    char a2[] = " We are happy.";
    ReplaceBlank(a2,30);
    char a3[] = "We are happy. ";
    ReplaceBlank(a3,30);
    char a4[] = "We   are happy. ";
    ReplaceBlank(a4,30);
}

void test1() {
    //输入的字符串中没有空格。
    char a1[] = "Wearehappy.";
    ReplaceBlank(a1,30);
}

void test2() {
    //特殊输入测试（字符串是个NULL指针、字符串是个空字符串、字符串只有一个空格字符、字符串中只有连续多个空格）。
    char a1[] = "";
    ReplaceBlank(a1,30);
    char a2[] = " ";
    ReplaceBlank(a2,30);
    char a3[] = "   ";
    ReplaceBlank(a3,30);
    ReplaceBlank(NULL,30);
}

int main()
{
//    test();
    test1();
    test2();
    return 0;
}
