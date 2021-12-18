#include <iostream>
#include <stack>
using namespace std;

//链表
struct ListNode {
    int m_nkey;
    ListNode *m_pNext;
};

void PrintListReversingly_Iteratively(ListNode *pHead) {
    //栈方式实现
    std::stack<ListNode *>nodes;
    ListNode *pNode = pHead;
    //遍历链表并加入栈中
    while (pNode != NULL) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    //打印栈中的元素
    while (!nodes.empty()) {
        pNode = nodes.top();
        printf("%d\t",pNode->m_nkey);
        nodes.pop();
    }
}


void test() {
    ListNode *n6 = new ListNode();
    n6->m_nkey = 6;
    n6->m_pNext = NULL;
    ListNode *n5 = new ListNode();
    n5->m_nkey = 5;
    n5->m_pNext = n6;
    ListNode *n4 = new ListNode();
    n4->m_nkey = 4;
    n4->m_pNext = n5;
    ListNode *n3 = new ListNode();
    n3->m_nkey = 3;
    n3->m_pNext = n4;
    ListNode *n2 = new ListNode();
    n2->m_nkey = 2;
    n2->m_pNext = n3;
    ListNode *n1 = new ListNode();
    n1->m_nkey = 1;
    n1->m_pNext = n2;
    PrintListReversingly_Iteratively(n1);
}

void PrintListReversingle_recursively(ListNode *pHead) {
    if (pHead != NULL) {
        if (pHead ->m_pNext != NULL) {
           PrintListReversingle_recursively(pHead->m_pNext);
        }
        printf("%d\t",pHead->m_nkey);
    }
}

void test2() {
    ListNode *n6 = new ListNode();
    n6->m_nkey = 6;
    n6->m_pNext = NULL;
    ListNode *n5 = new ListNode();
    n5->m_nkey = 5;
    n5->m_pNext = n6;
    ListNode *n4 = new ListNode();
    n4->m_nkey = 4;
    n4->m_pNext = n5;
    ListNode *n3 = new ListNode();
    n3->m_nkey = 3;
    n3->m_pNext = n4;
    ListNode *n2 = new ListNode();
    n2->m_nkey = 2;
    n2->m_pNext = n3;
    ListNode *n1 = new ListNode();
    n1->m_nkey = 1;
    n1->m_pNext = n2;
    PrintListReversingle_recursively(n1);
}

int main()
{

//    test();
    test2();
    return 0;
}
