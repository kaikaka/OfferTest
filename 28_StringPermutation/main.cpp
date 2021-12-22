#include <iostream>

using namespace std;

void Permutation(char *pStr, char *pBegin) {
    if (*pBegin == '\0') {
        printf("%s\n",pStr);
    } else {
        for (char * pCh = pBegin;*pCh != '\0';++ pCh) {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
            Permutation(pStr,pBegin + 1);

            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

void Permutation(char *pStr) {
    if (pStr == nullptr) return;
    Permutation(pStr,pStr);
}

void test() {
    char cArray[] ="abc";
    Permutation(cArray);

    char cArray1[] ="a";
    Permutation(cArray1);
}

int main()
{
    test();
    return 0;
}
