#include <iostream>
#include <set>
#include <vector>

using namespace std;

//第一个类型参数说明 multiset 容器中的每个元素都是 Key 类型的。第二个类型参数 Pred 用于指明容器中元素的排序规则，在被实例化后，Pred 可以是函数对象类，也可以是函数指针类型。
typedef multiset<int,greater<int>> intSet;
typedef multiset<int,greater<int>>::iterator setIterator ;

void GetLeastNumbers(const vector<int>& data,intSet & leastNumbers,int k) {
    leastNumbers.clear();
    if (k < 1 || data.size() < k) return;
    vector<int>:: const_iterator iter = data.begin();
    for (;iter != data.end(); ++ iter) {
        if ((leastNumbers.size()) < k) {
            leastNumbers.insert(*iter);
        } else {
            setIterator iterGreatest = leastNumbers.begin();
            if (*iter < *(leastNumbers.begin())) {
                if (*iter < *(leastNumbers.begin())) {
                    leastNumbers.erase(iterGreatest);
                    leastNumbers.insert(*iter);
                }
            }
        }
    }
}

void test() {
    vector<int> data = {4,5,1,6,2,7,3,8};
    intSet leastNum;
    GetLeastNumbers(data,leastNum,4);
    //遍历
    for (setIterator iter = leastNum.begin(); iter != leastNum.end();++iter) {
        cout << *iter << endl;
    }
}

int main()
{
    test();
    return 0;
}
