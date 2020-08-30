#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "SingleLinkedList.h"


struct Person
{
    char name[64];
    int age;
};


void myPrintPerson(void* data)
{
    struct Person* p = data;
    printf("姓名：%s  年龄：%d\n", p->name, p->age);
}


int myComparePerson(void* data1, void* data2)
{
    struct Person* p1 = data1;
    struct Person* p2 = data2;

    return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}


void test01()
{
    //准备数据
    struct Person p1 = { "亚瑟", 18 };
    struct Person p2 = { "妲己", 20 };
    struct Person p3 = { "安琪拉", 19 };
    struct Person p4 = { "凯", 21 };
    struct Person p5 = { "孙悟空", 999 };
    struct Person p6 = { "李白", 999 };

    //初始化链表
    LinkList mylist = init_LinkList();

    printf("链表长度为：%d\n", size_LinkList(mylist));

    //插入数据
    insert_LinkList(mylist, 0, &p1);
    insert_LinkList(mylist, 0, &p2);
    insert_LinkList(mylist, -1, &p3);
    insert_LinkList(mylist, 0, &p4);
    insert_LinkList(mylist, 1, &p5);
    insert_LinkList(mylist, 0, &p6);

    // 李白 凯 孙悟空 妲己 亚瑟 安琪拉

    //遍历
    foreach_LinkList(mylist, myPrintPerson);

    printf("链表长度为：%d\n", size_LinkList(mylist));

    //测试删除 
    removeByPos_LinkList(mylist, 4);

    printf("------------------\n");

    foreach_LinkList(mylist, myPrintPerson);
    printf("链表长度为：%d\n", size_LinkList(mylist));

    struct Person p = { "孙悟空", 999 };
    removeByValue_LinkList(mylist, &p, myComparePerson);

    printf("------------------\n");

    foreach_LinkList(mylist, myPrintPerson);
    printf("链表长度为：%d\n", size_LinkList(mylist));

    //测试清空
    clear_LinkList(mylist);

    //返回链表长度
    printf("链表长度为：%d\n", size_LinkList(mylist));

    //销毁
    destroy_Linklist(mylist);
    mylist = NULL;
}

int main() {

    test01();

    system("pause");

    return EXIT_SUCCESS;
}