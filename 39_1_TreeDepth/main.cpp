#include <iostream>

using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

//获取二叉树的深度
int TreeDepth(BinaryTreeNode *pRoot) {
    if (pRoot == nullptr)
        return 0;
    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);
    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
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
        int dep = TreeDepth(node1);
        cout << dep << endl;
}

int main()
{
    test();
    return 0;
}
