#include <iostream>

using namespace std;

//ASCII码的长度呢是一个字节，共8位，理论上可以表示256个字符

char FirstNotRepeatingChar(char * pString) {
    if (pString == nullptr)
        return '\0';
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for (unsigned int i = 0; i < tableSize; ++ i)
        hashTable[i] = 0;
    char * pHashKey = pString;
    while (*(pHashKey) != '\0') {
        hashTable[*(pHashKey++)] ++;
    }
    pHashKey = pString;
    while (*pHashKey != '\0') {
        if (hashTable[*pHashKey] == 1)
            return *pHashKey;
        pHashKey ++;
    }
    return '\0';
}

void test() {
    //功能测试（字符串中存在只出现一次的字符，字符串中不存在只出现一次字符，字符串中所有字符都只出现一次）。
    char * ps = "abaccdeff";
    char c = FirstNotRepeatingChar(ps);
    cout << c << endl;

    cout << "----" << endl;
    char * ps1 = "abbacceeff";
    char c1 = FirstNotRepeatingChar(ps1);
    cout << c1 << endl;
    cout << "----" << endl;

    char * ps2 = "abcdhf";
    char c2 = FirstNotRepeatingChar(ps2);
    cout << c2 << endl;
}

int main()
{
    test();
    return 0;
}
