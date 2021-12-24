#include <iostream>

using namespace std;

struct ListNode {
    int m_nKey;
    ListNode  *m_pNext;
};

unsigned int GetListLength(ListNode *pHead) {
    unsigned int nLength = 0;
    ListNode *pNode = pHead;
    while (pNode != NULL) {
        ++nLength;
        pNode = pNode->m_pNext;
    }
    return nLength;
}

ListNode *FindFirstCommonNode(ListNode *pHead1,ListNode *pHead2) {
    unsigned int nLength1 = GetListLength(pHead1);
    unsigned int nLength2 = GetListLength(pHead2);
    int nLengthDif = nLength1 - nLength2;

    ListNode *pListHeadLong = pHead1;
    ListNode *pListHeadShort = pHead2;
    //分配长链表和短链表
    if (nLength2 > nLength1) {
        pListHeadLong = pHead2;
        pListHeadShort = pHead1;
        nLengthDif = nLength2 - nLength1;
    }
    //先在长链表上走nLengthDif步
    for (int i = 0;i < nLengthDif; ++i) {
        pListHeadLong = pListHeadLong->m_pNext;
    }
    //再同时在两个链表上遍历
    while ((pListHeadLong != nullptr) && (pListHeadShort != nullptr) && (pListHeadLong != pListHeadShort)) {
        pListHeadLong = pListHeadLong->m_pNext;
        pListHeadShort = pListHeadShort->m_pNext;
    }
    //得到第一个公共结点
    ListNode *pFirstCommonNode = pListHeadLong;
    return pFirstCommonNode;
}


void test() {
//    功能测试（输入的两个链表有公共交点：第一个公共结点在链表的中间）。
    ListNode *node1 = new ListNode ();
    ListNode *node2 = new ListNode ();
    ListNode *node3 = new ListNode ();
    ListNode *node4 = new ListNode ();
    ListNode *node5 = new ListNode ();
    ListNode *node6 = new ListNode ();
    ListNode *node7 = new ListNode ();

    node1->m_nKey = 1;
    node1->m_pNext = node2;

    node2->m_nKey = 2;
    node2->m_pNext = node3;

    node3->m_nKey = 3;
    node3->m_pNext = node6;

    node4->m_nKey = 4;
    node4->m_pNext = node5;

    node5->m_nKey = 5;
    node5->m_pNext = node6;

    node6->m_nKey = 6;
    node6->m_pNext = node7;

    node7->m_nKey = 7;
    node7->m_pNext = nullptr;

    ListNode *n1 = FindFirstCommonNode(node1,node4);

    cout << n1->m_nKey << endl;

}


int main()
{
    test();
    return 0;
}
