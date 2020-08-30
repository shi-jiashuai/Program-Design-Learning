#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dynamicArray.h"

struct Person
{
	char name[64];
	int age;
};

void myPrintPerson(void* data)
{
	struct Person* p = data;
	printf("������ %s ���䣺%d\n", p->name, p->age);

}

int myComparePerson(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return  strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

int main() {

	//��ʼ����̬����
	struct dynamicArray* array = init_DynamicArray(5);

	//׼������
	struct Person p1 = { "��ɪ", 18 };
	struct Person p2 = { "槼�", 20 };
	struct Person p3 = { "������", 19 };
	struct Person p4 = { "��", 21 };
	struct Person p5 = { "�����", 999 };
	struct Person p6 = { "���", 999 };

	printf("��������ǰ�� ������%d  ��С��%d\n", array->m_capacity, array->m_size);

	//��������
    // �� 槼� ��� ������  ��ɪ  �����
	insert_DynamicArray(array, 0, &p1);
	insert_DynamicArray(array, 0, &p2);
	insert_DynamicArray(array, 1, &p3);
	insert_DynamicArray(array, 0, &p4);
	insert_DynamicArray(array, -1, &p5);
	insert_DynamicArray(array, 2, &p6);

	//��������
	foreach_DynamicArray(array, myPrintPerson);

	printf("�������ݺ� ������%d  ��С��%d\n", array->m_capacity, array->m_size);

	//����ɾ�� ��λ��ɾ��
	removeByPos_DynamicArray(array, 2);
	printf("---------------------\n");
	foreach_DynamicArray(array, myPrintPerson);
	printf("ɾ�����ݺ� ������%d  ��С��%d\n", array->m_capacity, array->m_size);

	struct Person  p = { "��ɪ", 18 };
	removeByValue_DynamicArray(array, &p, myComparePerson);
	printf("---------------------\n");
	foreach_DynamicArray(array, myPrintPerson);
	printf("ɾ�����ݺ� ������%d  ��С��%d\n", array->m_capacity, array->m_size);

	//��������
	destroy_DynamicArray(array);
	array = NULL;

	system("pause");
	return EXIT_SUCCESS;
}