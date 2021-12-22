#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

void FindPath(BinaryTreeNode *pRoot,int expectedSum,vector<int> & path,int & currentSum) {
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);
    //如果是叶子结点，并且路径上结点的和等于输入的值
    bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
    if (currentSum == expectedSum && isLeaf) {
        printf("A path is found:");
        vector<int>::iterator iter = path.begin();
        for(;iter != path.end(); ++ iter)
            printf("%d\t",*iter);
        printf("\n");
    }
    //如果不是叶子结点，则遍历它的子结点
    if (pRoot->m_pLeft != NULL)
        FindPath(pRoot->m_pLeft,expectedSum,path,currentSum);
    if (pRoot->m_pRight != NULL)
        FindPath(pRoot->m_pRight,expectedSum,path,currentSum);
    //在返回到父结点之前，在路径上删除当前结点，并在currentSum中减去当前结点的值
    currentSum -= pRoot->m_nValue;
    path.pop_back();
}

void FindPath(BinaryTreeNode *pRoot,int expectedSum) {
    if (pRoot == NULL)
        return;
    vector<int> path;
    int currentSum = 0;
    FindPath(pRoot,expectedSum,path,currentSum);
}

void test() {
    BinaryTreeNode *node1 = new BinaryTreeNode ();
        node1->m_nValue = 1;

        BinaryTreeNode *node2 = new BinaryTreeNode ();
        node2->m_nValue = 2;

        BinaryTreeNode *node3 = new BinaryTreeNode ();
        node3->m_nValue = 3;

        BinaryTreeNode *node4 = new BinaryTreeNode ();
        node4->m_nValue = 4;

        BinaryTreeNode *node5 = new BinaryTreeNode ();
        node5->m_nValue = 5;

        node1->m_pLeft = node2;
        node1->m_pRight = node3;
        node2->m_pLeft = node4;
        node2->m_pRight = node5;

        FindPath(node1,8);

}

int main()
{
    test();
    return 0;
}
