#include <iostream>

using namespace std;

class CMyString {
public:
    CMyString(char * pData = NULL) {
       m_pData = pData;
    }
    CMyString(const CMyString &str) {
        m_pData = str.m_pData;
    }
    ~CMyString() {

    }
    CMyString &operator=(const CMyString &str) {
        if (&str != this) {
            CMyString strTmep(str);
            char *pTemp = strTmep.m_pData;
            strTmep.m_pData = m_pData;
            m_pData = pTemp;
        }
        return *this;
    }
    char * getMyData() {
        return m_pData;
    }
private:
    char *m_pData;
};

//测试用例
void test() {
    //把一个CMyString的实例赋值给另外一个实例。
    char * hw = (char *)"hello world";
    CMyString str1(hw);
    CMyString str2 = str1;
    cout << str2.getMyData() << endl;
}

//把一个CMyString的实例赋值给它自己。
void test1() {
    char * hw = (char *)"hello world2";
    CMyString str1(hw);
    str1 = str1;
    cout << str1.getMyData() << endl;
}

//连续赋值。
void test2() {
    char * hw = (char *)"hello world3";
    CMyString str1(hw);
    CMyString str2 = str1;
    CMyString str3 = str2 = str1;
    cout << str3.getMyData() << endl;
}

int main()
{
    test();
    test1();
    test2();
    return 0;
}
