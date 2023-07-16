#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
using namespace std;

//��ͷ���������ͷָ��Lָ��ĵ�һ������Ϊͷ��㣬ͷ��㲻�������
//����ͷ���������ͷָ��Lָ�����һ��������ʵ�����ڴ�����ݵĽ��

typedef struct LNode{
	int data;          //������ ��ÿ�������һ������Ԫ��   
	struct LNode* next;  //ָ����ָ��ָ����һ���ڵ�
}LNode,*LinkList;

bool InitList(LinkList & L)  //���û�����&����ô�������޸ĵ�ͷָ��L��һ������Ʒ��
{
	L = (LNode*)malloc(sizeof(LNode));  //����һ��ͷ���
	if(L == NULL)    //�ڴ治�㣬����ʧ��
		return false;
	 L->next = NULL;   //ͷ���֮����ʱ��û�нڵ㣬��ֹ������
	return true;
}


void test() {
	LinkList L;  //����һ��ָ�������ָ��
	//��ʼ��һ���ձ� 
	InitList(L);
}


//ָ�����ĺ�����
//����������p���֮��������
bool InsertNextNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;   //�ڴ�����
	s->data = e;
	s->next = p->next;
	p->next = s;
	return  true;
}


//��λ�����(����ͷ���) 
bool ListInsrt(LinkList& L, int i, int e) {
	if (i < 1)
		return false;
	if (i == 1)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;  //ͷָ��ָ���½��
		return true;
	}
	LNode* p;  //ָ��pָ�� ��ǰɨ�赽�Ľ��
	p = L;
	int j = 1; //j��ʾָ��pָ��ĵڼ������
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


//�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩
bool InsertList(LinkList& L, int i, int e) {
	if (i < 1)
		return false;
	LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0; //��ǰpָ��ĵڼ������
	p = L;   //Lָ��һ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	//if (p == NULL) //iֵ���Ϸ�
	//	return false;
	//LNode* s = (LNode*)malloc(sizeof(LNode));
	//s->data = e;
	//s->next = p->next;
	//p->next = s;  //�����s���ӵ�p֮��
	//return true;  //����ɹ�

	return InsertNextNode(p, e);
}







//ָ������ǰ�����
//ǰ���������p���֮ǰ����Ԫ�� e
bool InsertPriorNode(LNode* p, int e) {
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->next = p->next;
	s->next = s;        //�½��s���ӵ�p֮��
	s->data = p->data; //��p��Ԫ�ظ��Ƶ�s��
	p->data = e;       //p ��Ԫ�ظ���Ϊ e
	return true;
}



////ͷ�巨������������㷨���£�
//LinkList List_HeadInsert(LinkList& L) {//������������LinkListǿ������һ��������
//	LNode* s; int x;
//	L = (LinkList)malloc(sizeof(LNode));// ����ͷ���
//	L->next = NULL;
//	scanf("%d", &x); //�������ֵ
//	while (x != 9999) {      //����9999��ʾ����
//		s = (LNode*)malloc(sizeof(LNode)); //�����½��
//		s->data = x;        //������ֵ��ֵ�������½���������
//		s->next = L->next; 
//		L->next = s;       //���½�������У�LΪͷָ��
//		scanf("%d",&x);
//	}
//	return L;
//}



//��λ��ɾ������ͷ��㣩
//ListDelete(&L, i, &e); ɾ��������ɾ�����е�i��λ�õ�Ԫ�أ�����e���ر�ɾ��Ԫ�ص�ֵ
//ɾ����i��λ�õ�Ԫ�أ��ҵ���i-1����㣬����ָ��ָ���i+1����㣬���ͷŵ�i����㣬��ͷ�����Կ�����0�����
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
	if (p == NULL)  //iֵ���Ϸ�
		return false;
	if (p->next == NULL)  //��i-1�����֮�����������
		return false;

	LNode* q = p->next;  //��qָ��ɾ�����
	e = q->data;   //��e���ر�ɾ��Ԫ�ص�ֵ
	p->next = q->next;  //��*q�������С��Ͽ���,p��nextָ��q��next 
	free(q);            //�ͷŽ��Ĵ洢�ռ�

	return true;
}

   

//ָ������ɾ��
//ɾ��ָ�����p
bool DeleteNode(LinkList L, LNode* p) {
	LNode* pre = L;  // ǰ���ڵ�
	while (pre->next != NULL && pre->next != p) 
		pre = pre->next;  // ���������ҵ�Ҫɾ���ڵ��ǰ���ڵ�
	
	if (pre->next == NULL) 
		return false;  // û���ҵ�Ҫɾ���ڵ��ǰ���ڵ㣬ֱ�ӷ���

	pre->next = p->next;  // ǰ���ڵ��ָ��ָ��Ҫɾ���ڵ����һ���ڵ�
	free(p);
	return true;
}



 
//�жϵ������Ƿ�Ϊ�գ���ͷ��㣩
bool Empty(LinkList L) {
	if (L->next == NULL)
		return true;
	else
		return false;
     }

	


//��λ���ң����ص�i��Ԫ�أ���ͷ��㣩
LNode* GetELem(LinkList L, int i) {   //LNode*ǿ�����Ƿ���һ���ڵ㣬��LinkList Lǿ��L��һ��������LNode*Lǿ��L��һ���ڵ�
	if (i < 0)
		return NULL;
	LNode* p;  //ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0; //��ǰpָ����ǵڼ������
	p = L;     //Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
	while (p != NULL && j < i) {    //ѭ���ҵ���i�����
		p = p->next;
		j++;  
	}
	return p;
	}


//��ֵ���ң��ҵ�������==e �Ľ��
LNode* LocateElem(LinkList L, int e) {
	LNode* p = L->next;
	//�ӵ�1����㿪ʼ����������Ϊe�Ľ��
	while (p != NULL && p->data != e)	
		p = p->next;

		return p; //�ҵ��󷵻ظý��ָ�룬���򷵻�NULL
}


//��һ��������ĳ���
int Length(LinkList L) {
	int len = 0;  //ͳ�Ʊ�
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		len++; 
	}
	return len;
}



//β�巨����������
LinkList List_TailInsert(LinkList& L) {  //������������
	int x;          //��Ԫ������Ϊ����
	L = (LinkList)malloc(sizeof(LNode));  //����ͷ���(��ʼ���ձ�
	LNode* s, * r = L;    //rΪ��Ϊָ��
	scanf("%d", &x);      //�������ֵ
	while (x != 9999) {   //����9999��ʾ����
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;             //rָ���µı�β��㣬��Զ����rָ�����һ�����
		scanf("%d", &x);
	}
	r->next = NULL;        //β���ָ���ÿ�
	return L;
}



//ͷ�巨����������
LinkList List_HeadInsert(LinkList &L) {  //���򴴽�������
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));   //����ͷ���
	L->next = NULL;     //��ʼΪ������
	std::cout << "��������ֵ" << std::endl;
	scanf("%d", &x);    //�������ֵ
	while (x != 9999) {    //����9999��ʾ����
		s = (LNode*)malloc(sizeof(LNode));    //�����½��
		s->data = x;
		s->next = L->next;
		L->next = s;       //���½�������У�LΪͷָ��
		scanf("%d", &x);
	}
	return L;
}



bool PrintList(LinkList& L) {
	if (L == NULL)
		return false;
	LNode* p = L;
	int j = 0;
	std::cout << "��ӡ������" << std::endl;
	while (p != NULL) {
		std::cout << p->next->data << std::endl;
		p = p->next;
		j++;
	}
	std::cout << "����ĳ���=" << j << std::endl;
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





