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
    printf("������ %s  ���䣺 %d \n", p->name, p->age);
}

void test01()
{

    //��ʼ������
    LinkList mylist = init_LinkList();

    //��������
    struct Person p1 = { NULL,"aaa", 10 };
    struct Person p2 = { NULL,"bbb", 20 };
    struct Person p3 = { NULL,"ccc", 30 };
    struct Person p4 = { NULL,"ddd", 40 };
    struct Person p5 = { NULL,"eee", 50 };

    //����ڵ�
    insert_LinkList(mylist, 0, &p1);
    insert_LinkList(mylist, 0, &p2);
    insert_LinkList(mylist, 1, &p3);
    insert_LinkList(mylist, -1, &p4);
    insert_LinkList(mylist, 0, &p5);

    //��������
    // eee bbb  ccc aaa ddd
    foreach_LinkList(mylist, myPrintPerson);

    //ɾ�� aaa
    removeByPos_ListList(mylist, 3);
    printf("-----------------------\n");
    foreach_LinkList(mylist, myPrintPerson);

    //��������
    destroy_LinkList(mylist);
    mylist = NULL;

}


int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}
