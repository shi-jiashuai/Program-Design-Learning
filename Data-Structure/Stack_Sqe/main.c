#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Stack_Sqe.h"

struct Person
{
    char name[64];
    int age;
};

void test01()
{
    //��ʼ��ջ
    SeqStack myStack = init_SeqStack();

    //��������
    struct Person p1 = { "aaa", 10 };
    struct Person p2 = { "bbb", 20 };
    struct Person p3 = { "ccc", 30 };
    struct Person p4 = { "ddd", 40 };
    struct Person p5 = { "eee", 50 };

    //��ջ
    push_SeqStack(myStack, &p1);
    push_SeqStack(myStack, &p2);
    push_SeqStack(myStack, &p3);
    push_SeqStack(myStack, &p4);
    push_SeqStack(myStack, &p5);

    printf("ջ��Ԫ�ظ���Ϊ��%d\n", size_SeqStack(myStack));

    //ջ��Ϊ�գ��鿴ջ��Ԫ�أ���ջ
    while (isEmpty_SeqStack(myStack) == 0) 
    {
        struct Person* p = top_SeqStack(myStack);
        printf("������%s ���䣺%d\n", p->name, p->age);

        //��ջ
        pop_SeqStack(myStack);
    }

    printf("ջ��Ԫ�ظ���Ϊ��%d\n", size_SeqStack(myStack));

    //����ջ
    destroy_SeqStack(myStack);
}

int main() 
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}