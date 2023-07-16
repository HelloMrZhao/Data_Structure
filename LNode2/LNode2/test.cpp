#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
using namespace std;

//带头结点的情况，头指针L指向的第一个结点称为头结点，头结点不存放数据
//不带头结点的情况，头指针L指向的下一个结点就是实际用于存放数据的结点

typedef struct LNode{
	int data;          //数据域 ，每个结点存放一个数据元素   
	struct LNode* next;  //指针域，指针指向下一个节点
}LNode,*LinkList;

bool InitList(LinkList & L)  //如果没有这个&，那么在下面修改的头指针L是一个复制品，
{
	L = (LNode*)malloc(sizeof(LNode));  //分配一个头结点
	if(L == NULL)    //内存不足，分配失败
		return false;
	 L->next = NULL;   //头结点之后暂时还没有节点，防止脏数据
	return true;
}


void test() {
	LinkList L;  //声明一个指向单链表的指针
	//初始化一个空表 
	InitList(L);
}


//指定结点的后插操作
//后插操作：在p结点之后插入操作
bool InsertNextNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;   //内存已满
	s->data = e;
	s->next = p->next;
	p->next = s;
	return  true;
}


//按位序插入(不带头结点) 
bool ListInsrt(LinkList& L, int i, int e) {
	if (i < 1)
		return false;
	if (i == 1)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;  //头指针指向新结点
		return true;
	}
	LNode* p;  //指针p指向 当前扫描到的结点
	p = L;
	int j = 1; //j表示指针p指向的第几个结点
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}


//在第i个位置插入元素e（带头结点）
bool InsertList(LinkList& L, int i, int e) {
	if (i < 1)
		return false;
	LNode* p;//指针p指向当前扫描到的结点
	int j = 0; //当前p指向的第几个结点
	p = L;   //L指向一个头结点，头结点是第0个结点（不存数据）
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	//if (p == NULL) //i值不合法
	//	return false;
	//LNode* s = (LNode*)malloc(sizeof(LNode));
	//s->data = e;
	//s->next = p->next;
	//p->next = s;  //将结点s连接到p之后
	//return true;  //插入成功

	return InsertNextNode(p, e);
}







//指定结点的前插操作
//前插操作：在p结点之前插入元素 e
bool InsertPriorNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->next = p->next;
	s->next = s;        //新结点s连接到p之后
	s->data = p->data; //将p中元素复制到s中
	p->data = e;       //p 中元素覆盖为 e
	return true;
}



////头插法建立点链表的算法如下：
//LinkList List_HeadInsert(LinkList& L) {//逆向建立单链表，LinkList强调的是一个单链表
//	LNode* s; int x;
//	L = (LinkList)malloc(sizeof(LNode));// 创建头结点
//	L->next = NULL;
//	scanf("%d", &x); //输入结点的值
//	while (x != 9999) {      //输入9999表示结束
//		s = (LNode*)malloc(sizeof(LNode)); //创建新结点
//		s->data = x;        //将结点的值赋值给创建新结点的数据域
//		s->next = L->next; 
//		L->next = s;       //将新结点插入表中，L为头指针
//		scanf("%d",&x);
//	}
//	return L;
//}



//按位序删除（带头结点）
//ListDelete(&L, i, &e); 删除操作，删除表中第i个位置的元素，并用e返回被删除元素的值
//删除第i个位置的元素：找到第i-1个结点，将其指针指向第i+1个结点，并释放第i个结点，，头结点可以看作第0个结点
bool ListDelete(LinkList& L, int i, int e) {
	if (i < 1)
		return false;
	LNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < j - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL)  //i值不合法
		return false;
	if (p->next == NULL)  //第i-1个结点之后无其他结点
		return false;

	LNode* q = p->next;  //令q指向被删除结点
	e = q->data;   //用e返回被删除元素的值
	p->next = q->next;  //将*q结点从链中“断开”,p的next指向q的next 
	free(q);            //释放结点的存储空间

	return true;
}

   

//指定结点的删除
//删除指定结点p
bool DeleteNode(LinkList L, LNode* p) {
	LNode* pre = L;  // 前驱节点
	while (pre->next != NULL && pre->next != p) 
		pre = pre->next;  // 遍历链表找到要删除节点的前驱节点
	
	if (pre->next == NULL) 
		return false;  // 没有找到要删除节点的前驱节点，直接返回

	pre->next = p->next;  // 前驱节点的指针指向要删除节点的下一个节点
	free(p);
	return true;
}



 
//判断单链表是否为空（带头结点）
bool Empty(LinkList L) {
	if (L->next == NULL)
		return true;
	else
		return false;
     }

	


//按位查找，返回第i个元素（带头结点）
LNode* GetELem(LinkList L, int i) {   //LNode*强调的是返回一个节点，而LinkList L强调L是一个单链表，LNode*L强调L是一个节点
	if (i < 0)
		return NULL;
	LNode* p;  //指针p指向当前扫描到的结点
	int j = 0; //当前p指向的是第几个结点
	p = L;     //L指向头结点，头结点是第0个结点（不存数据）
	while (p != NULL && j < i) {    //循环找到第i个结点
		p = p->next;
		j++;  
	}
	return p;
	}


//按值查找，找到数据域==e 的结点
LNode* LocateElem(LinkList L, int e) {
	LNode* p = L->next;
	//从第1个结点开始查找数据域为e的结点
	while (p != NULL && p->data != e)	
		p = p->next;

		return p; //找到后返回该结点指针，否则返回NULL
}


//求一个单链表的长度
int Length(LinkList L) {
	int len = 0;  //统计表长
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++; 
	}
	return len;
}



//尾插法建立单链表
LinkList List_TailInsert(LinkList& L) {  //正向建立单链表
	int x;          //设元素类型为整型
	L = (LinkList)malloc(sizeof(LNode));  //建立头结点(初始化空表）
	LNode* s, * r = L;    //r为标为指针
	scanf("%d", &x);      //输入结点的值
	while (x != 9999) {   //输入9999表示结束
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;             //r指向新的表尾结点，永远保持r指向最后一个结点
		scanf("%d", &x);
	}
	r->next = NULL;        //尾结点指针置空
	return L;
}



//头插法建立单链表
LinkList List_HeadInsert(LinkList &L) {  //逆向创建单链表
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));   //创建头结点
	L->next = NULL;     //初始为空链表
	std::cout << "请输入数值" << std::endl;
	scanf("%d", &x);    //输入结点的值
	while (x != 9999) {    //输入9999表示结束
		s = (LNode*)malloc(sizeof(LNode));    //创建新结点
		s->data = x;
		s->next = L->next;
		L->next = s;       //将新结点插入表中，L为头指针
		scanf("%d", &x);
	}
	return L;
}



bool PrintList(LinkList& L) {
	if (L == NULL)
		return false;
	LNode* p = L;
	int j = 0;
	std::cout << "打印单链表" << std::endl;
	while (p != NULL) {
		std::cout << p->next->data << std::endl;
		p = p->next;
		j++;
	}
	std::cout << "链表的长度=" << j << std::endl;
	return true;

}

	int main()
	{
		LinkList L;
		List_HeadInsert(L);
		PrintList(L);

		system("pause");
		return 0;
	}





