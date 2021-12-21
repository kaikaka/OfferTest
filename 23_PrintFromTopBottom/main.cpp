#include <iostream>
#include <queue>

using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

void PrintFromTopToButtom(BinaryTreeNode *pTreeRoot) {
    if (pTreeRoot == NULL) return;
    //deque 也可以
    queue<BinaryTreeNode *> queue;
    queue.push(pTreeRoot);
    while (!queue.empty()) {
        BinaryTreeNode *node = queue.front();
        cout << node->m_nValue << endl;
        queue.pop();
        if (node->m_pLeft != NULL)
            queue.push(node->m_pLeft);
        if (node->m_pRight != NULL)
            queue.push(node->m_pRight);
    }
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
        PrintFromTopToButtom(node1);
}

int main()
{
    test();
    return 0;
}
