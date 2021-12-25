#include <iostream>

using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

bool IsBalanced(BinaryTreeNode *pRoot,int *pDepth) {
    if (pRoot == nullptr) {
        *pDepth = 0;
        return true;
    }
    int left,right;
    if (IsBalanced(pRoot->m_pLeft,&left) && IsBalanced(pRoot->m_pRight,&right)) {
        int diff = left - right;
        if (diff <= 1 && diff >= -1) {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}

bool IsBalanced(BinaryTreeNode *pRoot) {
    int depth = 0;
    bool isB = IsBalanced(pRoot,&depth);
    cout << depth << endl;
    return isB;
}

void test() {
            BinaryTreeNode *node1 = new BinaryTreeNode ();
            node1->m_nValue = 1;

            BinaryTreeNode *node2 = new BinaryTreeNode ();
            node2->m_nValue = 2;

            BinaryTreeNode *node3 = new BinaryTreeNode ();
            node3->m_nValue = 3;

            BinaryTreeNode *node4 = new BinaryTreeNode ();
            node4->m_nValue = 4;

            BinaryTreeNode *node5 = new BinaryTreeNode ();
            node5->m_nValue = 5;

            node1->m_pLeft = node2;
            node1->m_pRight = node3;
            node2->m_pLeft = node4;
            node2->m_pRight = node5;
            IsBalanced(node1);
}

int main()
{
    test();
    return 0;
}
