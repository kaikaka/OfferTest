#include <iostream>
#include <iomanip>

using namespace std;

struct ListNode {
    int m_nValue;
    ListNode *m_pNext;
};

void DeleteNode(ListNode ** pListHead,ListNode *pToBeDeleted) {
    //如果不存在链表或要删除的结点
    if (!pListHead || !pToBeDeleted) return;
    //如果被删除的结点不是尾结点
    if (pToBeDeleted->m_pNext != NULL) {
        ListNode *pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;

        delete  pNext;
        pNext = NULL;
    } else if (pToBeDeleted == *pListHead) {
        //如果只有一个结点，删除并置空
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    } else {
        ListNode *pNode = *pListHead;
        //循环得到要删除结点的前序结点
        while (pNode->m_pNext != pToBeDeleted) {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = NULL;
        delete  pToBeDeleted;
        pToBeDeleted = NULL;
    }


    //打印输出
    ListNode *nt = *pListHead;
    while (nt != NULL) {
        cout << nt->m_nValue << endl;
        if (nt->m_pNext != NULL)
            nt = nt->m_pNext;
        else {
            nt = NULL;
        }
    }
}

void test() {
    //功能测试（从有多个结点的链表的中间删除一个结点，从有多个结点的链表中删除头结点，从有多个结点的链表中删除尾结点，从只有一个结点的链表中删除唯一的结点）
    ListNode *node1 = new ListNode ();
    node1->m_nValue = 1;
    node1->m_pNext = NULL;
    ListNode *node2 = new ListNode ();
    node2->m_nValue = 2;
    node2->m_pNext = node1;
    ListNode *node3 = new ListNode ();
    node3->m_nValue = 3;
    node3->m_pNext = node2;
    ListNode *node4 = new ListNode ();
    node4->m_nValue = 4;
    node4->m_pNext = node3;
    ListNode *node5 = new ListNode ();
    node5->m_nValue = 5;
    node5->m_pNext = node4;
    ListNode *node6 = new ListNode ();
    node6->m_nValue = 6;
    node6->m_pNext = node5;

    ListNode *node[] = {node6,node5,node4,node3,node2,node1};
    DeleteNode(node,node4);

    cout << "--------" << endl;
    ListNode *node7 = new ListNode ();
    node7->m_nValue = 1;
    node7->m_pNext = NULL;
    ListNode *node8 = new ListNode ();
    node8->m_nValue = 2;
    node8->m_pNext = node7;
    ListNode *node9 = new ListNode ();
    node9->m_nValue = 3;
    node9->m_pNext = node8;
    ListNode *node10 = new ListNode ();
    node10->m_nValue = 4;
    node10->m_pNext = NULL;
    ListNode *node11 = new ListNode ();
    node11->m_nValue = 5;
    node11->m_pNext = node10;
    ListNode *node12 = new ListNode ();
    node12->m_nValue = 6;
    node12->m_pNext = node11;

    ListNode **node111 = new ListNode*[3]();
    node111[0] = node12;
    node111[1] = node11;
    node111[2] = node10;

    DeleteNode(node111,node12);
    cout << "--------" << endl;
    ListNode **node112 = new ListNode*[3]();
    node112[0] = node9;
    node112[1] = node8;
    node112[2] = node7;
    DeleteNode(node112,node7);


    ListNode *node13 = new ListNode ();
    node13->m_nValue = 13;
    node13->m_pNext = NULL;
    cout << "--------" << endl;
    ListNode *node22[] = {node13};
    DeleteNode(node22,node13);
}

int main()
{
    test();
    return 0;
}
