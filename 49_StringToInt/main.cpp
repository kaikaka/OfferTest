#include <iostream>

using namespace std;

enum Status {kValid = 0,kInvalid};
int g_nStatus = kValid;

long long StrToIntCore(const char * digit,bool minus) {
    long long num = 0;
    while (*digit != '\0') {
        if (*digit >= '0' && *digit <= '9') {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0');
            if ((!minus && num > 0x7FFFFFFF)||
                    (minus && num < (signed int)0x80000000))  {
                num = 0;
                break;
            }
            digit ++;
        } else {
            num = 0;
            break;
        }
    }
    if (*digit == '\0') {
        g_nStatus = kValid;
    }
    return num;
}

int StrToInt(const char * str) {
    g_nStatus = kInvalid;
    long long num = 0;
    if (str != nullptr && *str != '\0') {
        bool minus = false;
        if (*str == '+')
            str ++;
        else if (*str == '-') {
            str ++;
            minus = true;
        }
        if (*str != '\0') {
            num = StrToIntCore(str,minus);
        }
    }
    return (int)num;
}

void test() {
    //功能测试（输入的字符串表示正数、负数和0）。
    int a = StrToInt("123");
    int b = StrToInt("-123");
    int c = StrToInt("0");
    cout << a << b << c << endl;
}

int main()
{
    test();
    return 0;
}
