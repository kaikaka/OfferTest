#include <iostream>

using namespace std;

void Reverse(char *pBegin, char *pEnd) {
    if (pBegin == nullptr || pEnd == nullptr)
        return;
    while (pBegin < pEnd) {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        pBegin ++;
        pEnd --;
    }
}

char * ReverseSentence(char *pData) {
    if (pData == nullptr)
        return nullptr;
    char *pBegin = pData;
    char *pEnd = pData;
    //让pend 指向字符串的尾部
    while (*pEnd != '\0') {
        pEnd ++;
    }
    pEnd --;
    //翻转整个字符串
    Reverse(pBegin,pEnd);
    //翻转句子中的每个单词
    pBegin = pEnd = pData;
    while (*pBegin != '\0') {
        if (*pBegin == ' ') {
            pBegin ++;
            pEnd ++;
        } else if (*pEnd == ' ' || *pEnd == '\0') {
            Reverse(pBegin,--pEnd);
            pBegin = ++ pEnd;
        } else {
            pEnd ++;
        }
    }
    return pData;
}

void test() {
    char array[] = "I am a student. ";
    char *rArray = ReverseSentence(array);
    cout << rArray << endl;
}

int main()
{
    test();
    return 0;
}
