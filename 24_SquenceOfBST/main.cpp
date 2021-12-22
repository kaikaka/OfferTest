#include <iostream>
#include <deque>

using namespace std;

bool VerifySquenceOfBST(int sequence[],int length) {
    if (sequence == NULL || length <= 0)
        return false;
    int root = sequence[length - 1];
    //在二叉搜索数中左子树的结点小于根结点
    int i = 0;
    for (;i < length - 1; ++ i) {
        if (sequence[i] > root)
            break;
    }
    //在二叉搜索树中右子树的结点大于根结点
    int j = i;
    for (;j < length - 1; ++ j) {
        if (sequence[j] < root)
            return false;
    }
    //判断左子树是不是二叉搜索树
    bool left = true;
    if (i > 0) {
        VerifySquenceOfBST(sequence,i);
    }
    //判断右子树是不是二叉搜索树
    bool right = true;
    if (i < length - 1)
       right = VerifySquenceOfBST(sequence + i,length - i - 1);
    return  left && right;
}

void test() {
    int seq[] = {5,7,6,9,11,10,8};
    bool isbst = VerifySquenceOfBST((int *)seq,7);
    cout << isbst << endl;

    int seq1[] = {7,4,6,5};
    bool isbst1 = VerifySquenceOfBST((int *)seq1,3);
    cout << isbst1 << endl;
}

int main()
{
    test();
    return 0;
}
