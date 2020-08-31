#pragma once

typedef void* LinkList;

//初始化链表
LinkList init_LinkList();

//插入
void insert_LinkList(LinkList list, int pos, void* data);

//遍历链表
void foreach_LinkList(LinkList list, void(*myForeach)(void*));

//删除节点 按位置删除
void removeByPos_ListList(LinkList list, int pos);

//销毁数组
void destroy_LinkList(LinkList list);