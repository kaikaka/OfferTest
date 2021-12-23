#include <iostream>

using namespace std;

//最大子数组的和
bool g_InvalidInput = true;
int FindGreatestSumOfSubArray(int *pData,int nLength) {
    if ((pData == NULL) || (nLength <= 0)) {
        g_InvalidInput = true;
        return 0;
    }
    g_InvalidInput = false;
    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for (int i = 0;i < nLength; ++i) {
        if (nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];
        if (nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }
    return nGreatestSum;
}

void test() {
    int array[] = {1,-2,3,10,-4,7,2,-5};
    int ngs = FindGreatestSumOfSubArray(array,8);
    cout << ngs << endl;
}

int main()
{
    test();
    return 0;
}
