#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct BinaryNode
{
    //数据域
    char ch;
    //指针域
    struct BinaryNode* lChild;
    struct BinaryNode* rChild;
};

//求叶子节点数量
void calculateLeafNum(struct BinaryNode* root, int* p);

//获取树高度
int getTreeHeight(struct BinaryNode* root);

//拷贝二叉树
struct BinaryNode* copyTree(struct BinaryNode* root);

//递归便利二叉树
void recursion(struct BinaryNode* root);

// 资源释放
void freeTree(struct BinaryNode* root);
