#include <iostream>
#include <list>

using namespace std;

int LastRemaining(unsigned int n,unsigned int m) {
    if (n < 1 || m < 1)
        return  -1;
    unsigned int i = 0;
    list<int> numbers;
    for (i = 0; i< n ; ++ i)
        numbers.push_back(i);
    list<int>:: iterator current  = numbers.begin();
    while (numbers.size() > 1) {
        for (int i = 1; i < m ; ++i) {
            current ++;
            if (current == numbers.end())
                current = numbers.begin();
        }
        list <int>:: iterator next = ++ current;
        if (next == numbers.end())
            next = numbers.begin();
        -- current;
        numbers.erase(current);
                current = next;
    }
    return *(current);
}

int LastRemaining2(unsigned int n, unsigned int m) {
    if (n < 1 || m < 1)
        return  -1;
    int last = 0;
    for (int i = 2;i <= n;i++)
        last = (last + m) % i;
    return last;
}

void test() {
    int r = LastRemaining(5,3);
    cout << r << endl;

    int z = LastRemaining2(8,3);
    cout << z << endl;
}

int main()
{
    test();
    return 0;
}
