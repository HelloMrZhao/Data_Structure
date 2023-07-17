#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
using namespace std;

//循环链表

//1.循环单链表

typedef struct LNode {  //定义单链表结点类型
	int data;           //每个单链表存放一个数据元素
	struct LNode* next;  //指针指向下一个节点
}LNode,*LinkList;

//初始化一个循环链表
bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));   //分配一个头结点
	if (L == NULL)                        //内存不足分配失败
		return false;
	L->next = L;
	return true;
}

//判断循环单链表是否为空
bool Empty(LinkList L) {
	if (L->next == L)
		return true;
	else
		return false;  
}

//判断结点p是否为循环单链表的表尾结点
bool isTail(LinkList L, LNode* p) {
	if (p->next == L)
		return true;
	else 
		return false;
}



//普通双链表：
//表头结点的prior指向NULL
//表尾结点的next指向NULL

//循环双链表：
//表头结点的prior只想表尾结点
//表尾结点的next指向头结点

typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode,*DLinkList;

//初始化空的循环双链表
bool InitDLinkList(DLinkList &L) {
	L = (DNode*)malloc(sizeof(DNode));  //分配一个头结点
	if (L == NULL)
		return false;
	L->prior = L;    //头结点的prior指向头结点
	L->next = L;      //头结点的next指向头结点
	return true;
}


//判断循环双链表是否为空
bool Empty(DLinkList L) {
	if (L->next == L)
		return true;
	else
		return false;
}


//循环双链表的插入
//在p结点之后插入s结点
bool InsertNextDNode(DNode* p, DNode* s) {
	s->next = p->next;    //将结点*s插入到结点*p之后
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

//双链表额删除
//删除p的后继结点
bool DeleteNextDNode(DLinkList &L, DNode* p) {
	if (p->next == L)
		return false;
	DNode* q = p->next;   //找到p的后继结点q
	p->next = q->next;
	q->next->prior = p;
	free(q);                 //释放结点空间
	return true;
}

int main()
{

	system("pause");
	return 0;
}

