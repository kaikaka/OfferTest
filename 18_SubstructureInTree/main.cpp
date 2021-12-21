#include <iostream>

using namespace std;

//二叉树
struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode * m_pLeft;
    BinaryTreeNode * m_pRight;
};

//判断树A中以R为根结点的子树是不是和树B具有相同的结构 递归终止条件到达树的叶子结点
bool DoesTree1HaveTree2(BinaryTreeNode *pRoot1,BinaryTreeNode *pRoot2) {
    if (pRoot2 == NULL)
        return true;
    if (pRoot1 == NULL)
        return false;
    if (pRoot1->m_nValue != pRoot2->m_nValue)
        return false;
    //递归遍历子树的左右结点是否一致
    return DoesTree1HaveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight,pRoot2->m_pRight);
}

bool HasSubtree(BinaryTreeNode *pRoot1,BinaryTreeNode *pRoot2) {
    bool result = false;
    if (pRoot1 != NULL && pRoot2 != NULL) {
        //如果根结点相等，查找子树
        if (pRoot1->m_nValue == pRoot2->m_nValue)
            result = DoesTree1HaveTree2(pRoot1,pRoot2);
        //否则遍历左子树
        if(!result)
            result = HasSubtree(pRoot1->m_pLeft,pRoot2);
        //继续遍历右子树
        if(!result)
            result = HasSubtree(pRoot1->m_pRight,pRoot2);
    }
    return result;
}

void test() {
//    功能测试（树A和树B都是普通的二叉树，树B是或者不是树A的子结构）。
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


    BinaryTreeNode *node20 = new BinaryTreeNode ();
    node20->m_nValue = 2;

    BinaryTreeNode *node21 = new BinaryTreeNode ();
    node21->m_nValue = 4;

    BinaryTreeNode *node22 = new BinaryTreeNode ();
    node22->m_nValue = 5;

    node20->m_pLeft = node21;
    node20->m_pRight = node22;

    bool ishave = HasSubtree(node1,node20);
    cout << ishave << endl;

    cout << "-----------" << endl;

    BinaryTreeNode *node30 = new BinaryTreeNode ();
    node30->m_nValue = 2;

    BinaryTreeNode *node31 = new BinaryTreeNode ();
    node31->m_nValue = 4;

    BinaryTreeNode *node32 = new BinaryTreeNode ();
    node32->m_nValue = 5;

    node30->m_pLeft = node31;
    node31->m_pRight = node32;
    //二叉树的所有结点都没有左子树或者右子树 且树B是或者不是树A的子结构

    bool ishave1 = HasSubtree(node1,node30);
    cout << ishave1 << endl;

    cout << "-----------" << endl;
    //特殊输入测试（两棵二叉树的一个或者两个根结点为NULL指针）。
    bool ishave2 = HasSubtree(node1,NULL);
    cout << ishave2 << endl;
}

int main()
{
    test();
    return 0;
}
