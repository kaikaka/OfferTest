#include <iostream>
#include <queue>

using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

void MirrorRecursively(BinaryTreeNode *pNode) {
    //如果结点为空，或者左左子树为空
    if ((pNode == NULL) || (pNode->m_pLeft == NULL && pNode->m_pRight)) {
        return;
    }
    //交换左右结点
    BinaryTreeNode *pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;
    if (pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);
    if (pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
}

void test() {
    //功能测试（普通的二叉树，二叉树的所有结点都没有左子树或者右子树，只有一个结点的二叉树）
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

        cout << "------" << endl;
        MirrorRecursively(node1);

        //打印二叉树
        queue<BinaryTreeNode*> tree;
        tree.push(node1);
        while (!tree.empty()) {
           BinaryTreeNode *node = tree.front();
           cout << node->m_nValue << endl;
           tree.pop();
           if (node->m_pLeft) {
               tree.push(node->m_pLeft);
           }
           if (node->m_pRight) {
               tree.push(node->m_pRight);
           }
        }
}

int main()
{
    test();
    return 0;
}
