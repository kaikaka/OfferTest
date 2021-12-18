#include <iostream>
#include <stack>

using namespace std;

template <typename  T> class CQueue {
public:
    CQueue(void) {}
    ~CQueue(void) {}
    void appendTail(const T& node) {
        stack1.push(node);
    }
    T deleteHead() {
        if (stack2.size() <= 0) {
            while (stack1.size() > 0) {
                //记录栈顶元素用于stack2
                T &data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        if (stack2.size() == 0)
            throw new exception();
        //记录栈顶元素用于返回
        T head = stack2.top();
        stack2.pop();
        return head;
    }
private:
    stack<T> stack1;
    stack<T> stack2;
};

class Person {
public:
    int m_age = 18;
};

void test() {
    //往空/非空的队列里添加、删除元素。
    CQueue<Person> queue;
    //异常
//    Person pend = queue.deleteHead();
//    cout << pend.m_age << endl;

   Person person1;
   person1.m_age = 1;

   Person person2;
   person2.m_age = 2;

   queue.appendTail(person2);
   queue.appendTail(person1);
   Person pHead = queue.deleteHead();
   cout << pHead.m_age << endl;
}

void test1() {
    //连续删除元素直至队列为空。
    CQueue<Person> queue;
    Person person1;
    person1.m_age = 1;

    Person person2;
    person2.m_age = 2;

    queue.appendTail(person2);
    queue.appendTail(person1);
    Person pHead = queue.deleteHead();
    cout << pHead.m_age << endl;
    Person pHead1 = queue.deleteHead();
    cout << pHead1.m_age << endl;
}

int main()
{
    test();
    test1();
    return 0;
}
