#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
using namespace std;

//ѭ������

//1.ѭ��������

typedef struct LNode {  //���嵥����������
	int data;           //ÿ����������һ������Ԫ��
	struct LNode* next;  //ָ��ָ����һ���ڵ�
}LNode,*LinkList;

//��ʼ��һ��ѭ������
bool InitList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));   //����һ��ͷ���
	if (L == NULL)                        //�ڴ治�����ʧ��
		return false;
	L->next = L;
	return true;
}

//�ж�ѭ���������Ƿ�Ϊ��
bool Empty(LinkList L) {
	if (L->next == L)
		return true;
	else
		return false;  
}

//�жϽ��p�Ƿ�Ϊѭ��������ı�β���
bool isTail(LinkList L, LNode* p) {
	if (p->next == L)
		return true;
	else 
		return false;
}



//��ͨ˫����
//��ͷ����priorָ��NULL
//��β����nextָ��NULL

//ѭ��˫����
//��ͷ����priorֻ���β���
//��β����nextָ��ͷ���

typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode,*DLinkList;

//��ʼ���յ�ѭ��˫����
bool InitDLinkList(DLinkList &L) {
	L = (DNode*)malloc(sizeof(DNode));  //����һ��ͷ���
	if (L == NULL)
		return false;
	L->prior = L;    //ͷ����priorָ��ͷ���
	L->next = L;      //ͷ����nextָ��ͷ���
	return true;
}


//�ж�ѭ��˫�����Ƿ�Ϊ��
bool Empty(DLinkList L) {
	if (L->next == L)
		return true;
	else
		return false;
}


//ѭ��˫����Ĳ���
//��p���֮�����s���
bool InsertNextDNode(DNode* p, DNode* s) {
	s->next = p->next;    //�����*s���뵽���*p֮��
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

//˫�����ɾ��
//ɾ��p�ĺ�̽��
bool DeleteNextDNode(DLinkList &L, DNode* p) {
	if (p->next == L)
		return false;
	DNode* q = p->next;   //�ҵ�p�ĺ�̽��q
	p->next = q->next;
	q->next->prior = p;
	free(q);                 //�ͷŽ��ռ�
	return true;
}

int main()
{

	system("pause");
	return 0;
}

