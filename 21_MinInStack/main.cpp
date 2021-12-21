#include <iostream>
#include <stack>

using namespace std;

template <typename T> class StackWithMin {
public:
    void push(const T& value);
    void pop();
    const T& min();
private:
    //数据栈
    stack<T> m_data;
    //辅助栈
    stack<T> m_min;
};

template <typename T> void StackWithMin<T>::push(const T& value) {
    m_data.push(value);
    //如果值比辅助栈的栈顶元素还小 加入辅助栈中,否则再次加下最小元素，保持辅助栈栈顶元素最小
    if (m_min.size() == 0 || value < m_min.top()) {
        m_min.push(value);
    } else {
        m_min.push(m_min.top());
    }
}

template <typename  T> void StackWithMin<T>::pop() {
    assert(m_data.size() > 0 && m_min.size() > 0);
    m_data.pop();
    m_min.pop();
}

template <typename T> const T & StackWithMin<T>::min() {
    assert(m_data.size() > 0 && m_min.size() > 0);
    //返回栈顶元素
    return m_min.top();
}

void test() {
    StackWithMin<int> sm;
    sm.push(3);
    //新压入栈的数字比之前的最小值大。
    sm.push(5);
    cout << "-----" << endl;
    int m = sm.min();
    cout << m << endl;

    //新压入栈的数字比之前的最小值小。
    cout << "-----" << endl;
    sm.push(2);
    int m1 = sm.min();
    cout << m1 << endl;
}

int main()
{
    test();

    return 0;
}
