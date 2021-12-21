#include <iostream>

using namespace std;

//第一步总是需要的，因为打印一圈至少有一步。如果只有一行，那么就不用第二步了。也就是需要第二步的前提条件是终止行号大于起始行号。
//需要第三步打印的前提条件是圈内至少有两行两列，也就是说除了要求终止行号大于起始行号之外，还要求终止列号大于起始列号。
//同理，需要打印第四步的前提条件是至少有三行两列，因此要求终止行号比起始行号至少大2，同时终止列号大于起始列号。

void PrintMatrixInCircle(int ** numbers, int columns,int rows,int start) {
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;

    //从左到右打印一行
    for (int i = start; i<= endX ; ++i) {
        int number = numbers[start][i];
        cout << number << " " << endl;
    }
    //从上到下打印一列
    if (start < endY) {
        for (int i = start + 1;i <= endY; ++i) {
            int number = numbers[i][endX];
            cout << number << " " << endl;
        }
    }
    //从右到左打印一行
    if (start < endX && start < endY) {
        for (int i = endX - 1; i>= start ; --i) {
            int number = numbers[endY][i];
            cout << number << " " << endl;
        }
    }
    //从下到上打印一行
    if (start < endX && start < endY - 1) {
        for (int i = endY - 1;i >= start + 1;--i) {
            int number = numbers[i][0];
            cout << number << " " << endl;
        }
    }
}

void PrintMatrixClockwisely(int ** number, int colums,int rows) {
    if (number == NULL || colums <= 0 || rows <= 0)
        return;
    int start = 0;
    while (colums > start * 2 && rows > start *2) {
        PrintMatrixInCircle(number,colums,rows,start);
        ++start;
    }
}

void test() {
//数组有多行多列、数组只有一行、数组中只有一列。
    int array1[] = {1,2,3,4};
    int array2[] = {5,6,7,8};
    int array3[] = {9,10,11,12};
    int array4[] = {13,14,15,16};
    int *array[4] = {array1,array2,array3,array4};
    PrintMatrixClockwisely(array,4,4);

    cout << "---------------" << endl;
    int *a1[1] = {array1};
    PrintMatrixClockwisely(a1,4,1);

    cout << "---------------" << endl;
    int array11[] = {1};
    int array21[] = {5};
    int array31[] = {9};
    int array41[] = {13};
    int *a2[] = {array11,array21,array31,array41};
    PrintMatrixClockwisely(a2,1,4);
}

int main()
{
    test();
    return 0;
}
