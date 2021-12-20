#include <iostream>

using namespace std;

struct ListNode {
  int m_nValue;
  ListNode *m_pNext;
};

ListNode *Merge(ListNode *pHead1,ListNode *pHead2) {
    if (pHead1 == NULL) {
        return pHead2;
    } else if (pHead2 == NULL) {
        return pHead1;
    }
    ListNode *pMergedHead = NULL;
    //链表1 结点的值小于链表2的值 递归
    if (pHead1->m_nValue < pHead2->m_nValue) {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = Merge(pHead1->m_pNext,pHead2);
    } else {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = Merge(pHead1,pHead2->m_pNext);
    }
    return pMergedHead;
}

void test() {
//功能测试（输入的两个链表有多个结点，结点的值互不相同或者存在值相等的多个结点）。
    ListNode *node1 = new ListNode ();
    node1->m_nValue = 4;
    node1->m_pNext = NULL;
    ListNode *node2 = new ListNode ();
    node2->m_nValue = 3;
    node2->m_pNext = node1;
    ListNode *node3 = new ListNode ();
    node3->m_nValue = 1;
    node3->m_pNext = node2;

    ListNode *node4 = new ListNode ();
    node4->m_nValue = 6;
    node4->m_pNext = node3;
    ListNode *node5 = new ListNode ();
    node5->m_nValue = 5;
    node5->m_pNext = node4;
    ListNode *node6 = new ListNode ();
    node6->m_nValue = 2;
    node6->m_pNext = node5;

    ListNode *n1[] = {node3,node2,node1};
    ListNode *n2[] = {node6,node5,node4};
    ListNode *pMergedHead = Merge(*n1,*n2);
    int count = 0;
    while (count < 6) {
        count ++;
        cout << pMergedHead->m_nValue << endl;
        pMergedHead = pMergedHead->m_pNext;
    }
}

int main()
{
    test();
    return 0;
}
