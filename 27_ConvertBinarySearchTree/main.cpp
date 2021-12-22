#include <iostream>
#include <stack>

using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

void ConvertNode(BinaryTreeNode *pNode,BinaryTreeNode **pLastNodeInList) {
    if (pNode == NULL) return;
    BinaryTreeNode *pCurrent = pNode;
    if (pCurrent->m_pLeft != NULL)
        ConvertNode(pCurrent->m_pLeft,pLastNodeInList);
    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList != NULL)
        (*pLastNodeInList)->m_pRight = pCurrent;
    *pLastNodeInList = pCurrent;
    if (pCurrent->m_pRight != NULL)
        ConvertNode(pCurrent->m_pRight,pLastNodeInList);
}

BinaryTreeNode * Convert(BinaryTreeNode *pRootOfTree) {
    BinaryTreeNode *pLastNodeInList = NULL;
    ConvertNode(pRootOfTree,&pLastNodeInList);
    BinaryTreeNode *pHeadOfList = pLastNodeInList;
    while (pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL) {
        pHeadOfList = pHeadOfList->m_pLeft;
    }
    return pHeadOfList;
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

        node3->m_pLeft = node2;
        node3->m_pRight = node4;
        node2->m_pLeft = node1;
        node4->m_pRight = node5;
        Convert(node1);

        //中序遍历
        stack<BinaryTreeNode *>stack;
        BinaryTreeNode *root = node3;
        while (root != nullptr || !stack.empty()) {
            if (root != nullptr) {
                stack.push(root);
                root = root->m_pLeft;
            } else {
                root = stack.top();
                stack.pop();
                cout << root->m_nValue << endl;
                root = root->m_pRight;
            }
        }

}

int main()
{
    test();
    return 0;
}
