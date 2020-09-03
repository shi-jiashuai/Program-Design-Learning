#define _CRT_SECURE_NO_WARNINGS
#include "queue_seq.h"

struct Person
{
    char name[64];
    int age;
};

void test01()
{
    //��ʼ������
    seqQueue myQueue = init_SeqQueue();

    //׼������
    struct Person p1 = { "aaa", 10 };
    struct Person p2 = { "bbb", 20 };
    struct Person p3 = { "ccc", 30 };
    struct Person p4 = { "ddd", 40 };

    //���
    push_SeqQueue(myQueue, &p1);
    push_SeqQueue(myQueue, &p2);
    push_SeqQueue(myQueue, &p3);
    push_SeqQueue(myQueue, &p4);
    printf("���д�СΪ��%d\n", size_SeqQueue(myQueue));
    while (isEmpty_SeqQueue(myQueue) == 0)
    {
        //���ʶ�ͷ
        struct Person* pFront = front_SeqQueue(myQueue);
        printf("��ͷԪ�� -- ������%s  ���䣺 %d\n", pFront->name, pFront->age);
        //���ʶ�β
        struct Person* pBack = back_SeqQueue(myQueue);
        printf("��βԪ�� -- ������%s  ���䣺 %d\n", pBack->name, pBack->age);
        //����
        pop_SeqQueue(myQueue);
    }

    printf("���д�СΪ��%d\n", size_SeqQueue(myQueue));

    //���ٶ���
    destroy_SeqQueue(myQueue);
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}