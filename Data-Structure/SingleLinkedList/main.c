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
    printf("������%s  ���䣺%d\n", p->name, p->age);
}


int myComparePerson(void* data1, void* data2)
{
    struct Person* p1 = data1;
    struct Person* p2 = data2;

    return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}


void test01()
{
    //׼������
    struct Person p1 = { "��ɪ", 18 };
    struct Person p2 = { "槼�", 20 };
    struct Person p3 = { "������", 19 };
    struct Person p4 = { "��", 21 };
    struct Person p5 = { "�����", 999 };
    struct Person p6 = { "���", 999 };

    //��ʼ������
    LinkList mylist = init_LinkList();

    printf("������Ϊ��%d\n", size_LinkList(mylist));

    //��������
    insert_LinkList(mylist, 0, &p1);
    insert_LinkList(mylist, 0, &p2);
    insert_LinkList(mylist, -1, &p3);
    insert_LinkList(mylist, 0, &p4);
    insert_LinkList(mylist, 1, &p5);
    insert_LinkList(mylist, 0, &p6);

    // ��� �� ����� 槼� ��ɪ ������

    //����
    foreach_LinkList(mylist, myPrintPerson);

    printf("������Ϊ��%d\n", size_LinkList(mylist));

    //����ɾ�� 
    removeByPos_LinkList(mylist, 4);

    printf("------------------\n");

    foreach_LinkList(mylist, myPrintPerson);
    printf("������Ϊ��%d\n", size_LinkList(mylist));

    struct Person p = { "�����", 999 };
    removeByValue_LinkList(mylist, &p, myComparePerson);

    printf("------------------\n");

    foreach_LinkList(mylist, myPrintPerson);
    printf("������Ϊ��%d\n", size_LinkList(mylist));

    //�������
    clear_LinkList(mylist);

    //����������
    printf("������Ϊ��%d\n", size_LinkList(mylist));

    //����
    destroy_Linklist(mylist);
    mylist = NULL;
}

int main() {

    test01();

    system("pause");

    return EXIT_SUCCESS;
}