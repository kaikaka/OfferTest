#include <iostream>
#include <deque>

using namespace std;

struct ComplexListNode {
    int m_nValue;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
};

//复制链表
void CloneNodes(ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    while (pNode != NULL) {
        ComplexListNode *pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        //pCloned->m_pSibling = NULL;原码这里写的有待考虑

        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;
    }
}

// 链接SiblingNode
void ConnectSiblingNodes(ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    while (pNode != NULL) {
        ComplexListNode *pCloned = pNode->m_pNext;
        if (pNode->m_pSibling != NULL) {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        pNode = pCloned->m_pNext;
    }
}

//拆分长链表
ComplexListNode *ReconnectNodes(ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    ComplexListNode *pCloneHead = NULL;
    ComplexListNode *pCloneNode = NULL;
    if (pNode != NULL) {
        pCloneHead = pCloneNode = pNode->m_pNext;
        pNode->m_pNext = pCloneNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    while (pNode != NULL) {
        pCloneNode->m_pNext = pNode->m_pNext;
        pCloneNode = pCloneNode->m_pNext;
        pNode->m_pNext = pCloneNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pCloneHead;
}

ComplexListNode *Clone(ComplexListNode *pHead) {
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

void test() {
        ComplexListNode *node1 = new ComplexListNode ();
        node1->m_nValue = 1;

        ComplexListNode *node2 = new ComplexListNode ();
        node2->m_nValue = 2;

        ComplexListNode *node3 = new ComplexListNode ();
        node3->m_nValue = 3;

        ComplexListNode *node4 = new ComplexListNode ();
        node4->m_nValue = 4;

        ComplexListNode *node5 = new ComplexListNode ();
        node5->m_nValue = 5;

        node1->m_pNext = node2;
        node1->m_pSibling = node3;
        node2->m_pNext = node4;
        node2->m_pSibling = node5;

        ComplexListNode *node = Clone(node1);

        deque<ComplexListNode *> queue;
        queue.push_back(node1);
        while (!queue.empty()) {
            ComplexListNode * cNode = queue.front();
            cout << cNode->m_nValue << endl;
            queue.pop_front();
            if (cNode->m_pNext != 0) {
                queue.push_back(cNode->m_pNext);
            }
            if (cNode->m_pSibling != 0)
                queue.push_back(cNode->m_pSibling);
        }
}

int main()
{
    test();
    return 0;
}
