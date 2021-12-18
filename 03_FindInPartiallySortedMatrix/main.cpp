#include <iostream>

using namespace std;

//number 是要查找的数字
bool find(int *matrix, int rows,int columns, int number) {
    bool found = false;
    if (matrix != NULL && rows > 0 && columns > 0) {
        int row = 0;
        int column = columns - 1;
        //遍历完数组退出循环
        while (row < rows && column >= 0) {
            //右上角的坐标 = 当前行 * 总列数 + 当前列
            if (matrix[row * columns + column] == number) {
                found = true;
                break;
            } else if (matrix[row * columns + column] > number) {
                //大于number 则删除当前列
                -- column;
            } else {
                //否则删除当前行，因为row是从0开始，所以删除是++
                ++ row;
            }
        }
    }
    return found;
}

void test() {
//    二维数组中包含查找的数字（查找的数字是数组中的最大值和最小值，查找的数字介于数组中的最大值和最小值之间）。
    int a1[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    bool found = find((int *)&a1,4,4,7);
    cout << found << endl;
    bool found1 = find((int *)&a1,4,4,15);
    cout << found1 << endl;
    bool found2 = find((int *)&a1,4,4,1);
    cout << found2 << endl;
    //输出结果1，1，1
}

void test1() {
//    二维数组中没有查找的数字（查找的数字大于数组中的最大值，查找的数字小于数组中的最小值，查找的数字在数组的最大值和最小值之间但数组中没有这个数字）
    int a1[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    bool found = find((int *)&a1,4,4,5);
    cout << found << endl;
    bool found1 = find((int *)&a1,4,4,16);
    cout << found1 << endl;
    bool found2 = find((int *)&a1,4,4,0);
    cout << found2 << endl;
    //输出结果0，0，0
}

void test2() {
//    特殊输入测试（输入空指针）。
    int a1[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    bool found = find(NULL,4,4,5);
    cout << found << endl;
    //输出结果0
}

int main()
{
    test();
    test1();
    test2();
    return 0;
}
