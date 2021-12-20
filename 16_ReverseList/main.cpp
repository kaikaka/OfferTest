#include <iostream>

using namespace std;

struct ListNode {
    int m_nValue;
    ListNode *m_pNext;
};

ListNode * reverseList(ListNode *pHead) {
    ListNode *pReversedHead = NULL;
    ListNode *pNode = pHead;
    ListNode *pPrev = NULL;
    while (pNode != NULL) {
        ListNode *pNext = pNode->m_pNext;
        //如果是尾结点，转换成头结点
        if (pNext == NULL)
            pReversedHead = pNode;

        pNode->m_pNext = pPrev;

        //结点转换
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}

void test() {
//功能测试（输入的链表含有多个结点，链表中只有一个结点）。
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
            ListNode *pHead = reverseList(*node);
            int count = 0;
            while (count < 6) {
                cout << pHead->m_nValue << endl;
                if (pHead->m_pNext != NULL) {
                    pHead = pHead->m_pNext;
                }
                ++count;
            }


            ListNode *node7 = new ListNode ();
            node7->m_nValue = 7;
            node7->m_pNext = NULL;

            cout << "--------" << endl;
            ListNode *node11[] = {node7};
            ListNode *pHead1 = reverseList(*node11);
            int count1 = 0;
            while (count1 < 1) {
                cout << pHead1->m_nValue << endl;
                if (pHead1->m_pNext != NULL) {
                    pHead1 = pHead1->m_pNext;
                }
                ++count1;
            }
}

int main()
{
    test();
    return 0;
}
