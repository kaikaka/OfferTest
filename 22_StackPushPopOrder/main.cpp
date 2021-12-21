#include <iostream>
#include <stack>

using namespace std;

bool IsPopOrder(const int *pPush,const int *pPop,int nLength) {
    bool bPossible = false;
    if (pPush != NULL && pPop != NULL && nLength > 0) {
        const int * pNextPush = pPush;//压栈的索引
        const int * pNextPop = pPop;//出栈序列的索引
        stack<int> stackData;

        //出栈序列到尾部跳出循环
        while (pNextPop - pPop < nLength) {
            //压栈顺序(如果栈顶元素等于出栈的元素说明找到出栈结点)
            while (stackData.empty() || stackData.top() != *pNextPop) {
                //压栈完毕
                if (pNextPush - pPush == nLength)
                    break;
                stackData.push(*pNextPush);
                pNextPush ++;
            }
            //找到结点后出栈
            if (stackData.top() != *pNextPop)
                break;
            stackData.pop();
            pNextPop ++;
        }
        if (stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}

void test() {
    int pushArray[] = {1,2,3,4,5};
    int popArray[] = {4,5,3,2,1};
    bool isp = IsPopOrder((int *)pushArray,(int *)popArray,5);
    cout << isp << endl;
}

int main()
{
    test();
    return 0;
}
