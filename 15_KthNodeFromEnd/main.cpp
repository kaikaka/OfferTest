#include <iostream>

using namespace std;

struct ListNode {
    int m_nValue;
    ListNode *m_pNext;
};

ListNode* findKthToTail(ListNode *pListHead,unsigned int k) {
    if (pListHead == NULL || k == 0) return NULL;
    ListNode *pAhead = pListHead;
    ListNode *pBehind = NULL;
    //将第一个指针指向k-1
    for (unsigned int i = 0;i< k -1; ++ i) {
        if (pAhead->m_pNext != NULL)
            pAhead = pAhead->m_pNext;
        else
            return NULL;

    }
    //第二个指针
    pBehind = pListHead;
    //退出循环条件是到达尾结点
    while (pAhead->m_pNext != NULL) {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}

void test() {
    //功能测试（第k个结点在链表的中间，第k个结点是链表的头结点，第k个结点是链表的尾结点）。
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
        ListNode *behind = findKthToTail(*node,2);
        cout << behind->m_nValue << endl;

        ListNode *behind1 = findKthToTail(*node,1);
        cout << behind1->m_nValue << endl;
        ListNode *behind2 = findKthToTail(*node,6);
        cout << behind2->m_nValue << endl;
        //特殊输入测试（链表头结点为NULL指针，链表的结点总数少于k，k等于0）。
        ListNode *behind3 = findKthToTail(NULL,2);
        if (behind3 != NULL) {
           cout << behind3->m_nValue << endl;
        }

        ListNode *behind4 = findKthToTail(*node,20);
        if (behind3 != NULL) {
           cout << behind4->m_nValue << endl;
        }
}

int main()
{
    test();
    return 0;
}
