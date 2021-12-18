#include <iostream>
#include <exception>

using namespace std;

//二叉树
struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

BinaryTreeNode * ContructCore(int *startPreorder,int * endPreorder,int * startInorder,int * endInorder) {
    //前序遍历第一个结点是根结点
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    if (startPreorder == endPreorder) {
        //只有根结点的情况
        if (startInorder == endInorder && *startPreorder == *startInorder) {
            return root;
        } else
            throw  std::exception();
    }
    //在中序遍历中找到根结点的值
    int *rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue) {
        ++ rootInorder;
    }
    if (rootInorder == endInorder && *rootInorder != rootValue) {
        throw  std::exception();
    }
    //构建左右子树
    int leftLength = rootInorder - startInorder;
    int * leftPreorderEnd = startPreorder + leftLength;
    //如果有左子树
    if (leftLength > 0) {
        //startPreorder + 1 是左子树的根结点  rootInorder是中序遍历根结点所在的位置
        root->m_pLeft = ContructCore(startPreorder + 1,leftPreorderEnd,startInorder,rootInorder - 1);
    }
    //如果有右子树
    if (leftLength < endPreorder - startPreorder) {
        //leftPreorderEnd 左子树的深度
        root->m_pRight = ContructCore(leftPreorderEnd + 1,endPreorder,rootInorder + 1,endInorder);
    }
    return root;
}

BinaryTreeNode * Construct(int * preorder,int *inorder,int length) {
    if (preorder == NULL || inorder == NULL || length <= 0)
        return NULL;
    return ContructCore(preorder,preorder + length - 1,inorder, inorder + length - 1);
}

void test() {
    //不完全二叉树
    int pre[] = {1,2,4,7,3,5,6,8};
    int in[] = {4,7,2,1,5,3,8,6};

    BinaryTreeNode *node = Construct((int *)pre,(int *)in,8);
    printf("%d\n",node->m_nValue);

    //完全二叉树
    int pre1[] = {4,2,1,3,6,5,7};
    int in1[] = {1,2,3,4,5,6,7};

    BinaryTreeNode *node1 = Construct((int *)pre1,(int *)in1,7);
    printf("%d\n",node1->m_nValue);
}

void test1() {
    //特殊二叉树（所有结点都没有右子结点的二叉树，所有结点都没有左子结点的二叉树，只有一个结点的二叉树）。
    //没有右结点
    int pre[] = {1,2,4,7};
    int in[] = {4,7,2,1};

    BinaryTreeNode *node = Construct((int *)pre,(int *)in,4);
    printf("%d\n",node->m_nValue);
    //没有左结点
    int pre1[] = {4,6,5,7};
    int in1[] = {4,5,6,7};

    BinaryTreeNode *node1 = Construct((int *)pre1,(int *)in1,4);
    printf("%d\n",node1->m_nValue);
    //只有一个结点
    int pre2[] = {6};
    int in2[] = {6};

    BinaryTreeNode *node2 = Construct((int *)pre2,(int *)in2,1);
    printf("%d\n",node2->m_nValue);
}

int main()
{
    test();
    test1();
    return 0;
}
