#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#define MaxSize 10

//��̬˳���ĳ�ʼ����д��Ԫ�غʹ�ӡ
//��̬˳����ڵ�i��λ�ò���Ԫ��e
//��̬˳����ڵ�i��λ��ɾ��Ԫ��e,������e

//����һ����̬����Ľṹ��
typedef struct 
{
	int data[MaxSize];
	int length;
}SeqList; //˳�������Ͷ���


//��ʼ��˳���
void InitList(SeqList* L) {
	for (int i = 0; i < MaxSize; i++)
		L->data[i] = 0;
	    L->length = 0;
	//return true;
}


//��˳���д������
int InsertData(SeqList* L) {
	if (L->length >= MaxSize) {
		printf("˳���洢�ռ�����\n");
		return 0;
	}
		while (L->length < MaxSize-1)
		{
			L->data[L->length] = L->length;
			L->length++;
		}
		return 1;
}


//��˳����i��λ�ò���һ��Ԫ��e
bool ListInsert(SeqList* L, int i ,int value) {
	if (i < 1 || L->length >= MaxSize ) {
		printf("����λ�÷Ƿ�\n");
		return false;
	}

	if (L->length >= MaxSize) {
		printf("˳����������޷���������\n");
		return false;
	}

	//i�Ժ��Ԫ�غ���
	for (int j = L->length; j >= i; j--)
		L->data[j] = L->data[j - 1];  //Ԫ�غ���
	L->data[i - 1] = value;   //��Ԫ�ز��뵽��i��λ��
	L->length++;   //���ȼ�һ
	return true;
}

//ɾ��˳����i��λ�õ�Ԫ��e,����e����
bool ListDelet(SeqList*L, int i, int*e){
	if (i<1 || i>L->length) {  //�ж�i�ķ�Χ�Ƿ���Ч
		printf("ɾ��λ�÷Ƿ�\n");
		return false;
	}
	*e = L->data[i - 1];
	for (int j = i; j < L->length; j++)  //����i��λ�ú��Ԫ��ǰ��
		L->data[j - 1] = L->data[j];
	L->length--;
	return true;
}


//��ӡ˳���
void PrintList(SeqList L) {
	if (L.length > MaxSize) {
		printf("���Ա����\n");
	}
	for (int i = 0; i < L.length; i++)
		printf("data[%d]=%d\n", i, L.data[i]);
}

int main()
{
	SeqList L;   //����һ��˳���
	InitList(&L);

	L.data[0] = 30;
	L.length++;
	L.data[1] = 31;
	L.length++;
	L.data[2] = 33;
	L.length++;

	InsertData(&L);
	PrintList(L);   //��ӡ˳���
	printf("-----------------------------------------\n");
	ListInsert(&L, 8, 66);
	PrintList(L);   //��ӡ˳���

	printf("-----------------------------------------\n");
	int e = 0;
	ListDelet(&L, 2, &e);
	PrintList(L);   //��ӡ˳���
	printf("%d\n", e);
	return 0;
}