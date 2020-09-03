#include "BinaryTree.h"

void test01()
{
    struct BinaryNode nodeA = { 'A', NULL, NULL };
    struct BinaryNode nodeB = { 'B', NULL, NULL };
    struct BinaryNode nodeC = { 'C', NULL, NULL };
    struct BinaryNode nodeD = { 'D', NULL, NULL };
    struct BinaryNode nodeE = { 'E', NULL, NULL };
    struct BinaryNode nodeF = { 'F', NULL, NULL };
    struct BinaryNode nodeG = { 'G', NULL, NULL };
    struct BinaryNode nodeH = { 'H', NULL, NULL };

    //建立关系
    nodeA.lChild = &nodeB;
    nodeA.rChild = &nodeF;
    nodeB.rChild = &nodeC;
    nodeC.lChild = &nodeD;
    nodeC.rChild = &nodeE;
    nodeF.rChild = &nodeG;
    nodeG.lChild = &nodeH;

    //1、求二叉树 叶子数量
    int num = 0;
    calculateLeafNum(&nodeA, &num);
    printf("树的叶子数量为：%d\n", num);


    //2、 求树的高度/深度
    int height = getTreeHeight(&nodeA);
    printf("树的高度为：%d\n", height);


    //3、 拷贝二叉树
    struct BinaryNode* newTree = copyTree(&nodeA);

    //递归遍历
    recursion(newTree);
    printf("\n");

    //4、 释放二叉树
    freeTree(newTree);
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}