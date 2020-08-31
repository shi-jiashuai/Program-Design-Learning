#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList_SinglePointer.h"

struct Person
{
    void* node;
    char name[64];
    int age;
};


void myPrintPerson(void* data)
{
    struct Person* p = data;
    printf("姓名： %s  年龄： %d \n", p->name, p->age);
}

void test01()
{

    //初始化链表
    LinkList mylist = init_LinkList();

    //创建数据
    struct Person p1 = { NULL,"aaa", 10 };
    struct Person p2 = { NULL,"bbb", 20 };
    struct Person p3 = { NULL,"ccc", 30 };
    struct Person p4 = { NULL,"ddd", 40 };
    struct Person p5 = { NULL,"eee", 50 };

    //插入节点
    insert_LinkList(mylist, 0, &p1);
    insert_LinkList(mylist, 0, &p2);
    insert_LinkList(mylist, 1, &p3);
    insert_LinkList(mylist, -1, &p4);
    insert_LinkList(mylist, 0, &p5);

    //遍历链表
    // eee bbb  ccc aaa ddd
    foreach_LinkList(mylist, myPrintPerson);

    //删除 aaa
    removeByPos_ListList(mylist, 3);
    printf("-----------------------\n");
    foreach_LinkList(mylist, myPrintPerson);

    //销毁数组
    destroy_LinkList(mylist);
    mylist = NULL;

}


int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}
