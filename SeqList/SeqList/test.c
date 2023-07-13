#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#define MaxSize 10

//静态顺序表的初始化、写入元素和打印
//静态顺序表在第i个位置插入元素e
//静态顺序表在第i个位置删除元素e,并返回e

//定义一个静态数组的结构体
typedef struct 
{
	int data[MaxSize];
	int length;
}SeqList; //顺序表的类型定义


//初始化顺序表
void InitList(SeqList* L) {
	for (int i = 0; i < MaxSize; i++)
		L->data[i] = 0;
	    L->length = 0;
	//return true;
}


//给顺序表写入数据
int InsertData(SeqList* L) {
	if (L->length >= MaxSize) {
		printf("顺序表存储空间已满\n");
		return 0;
	}
		while (L->length < MaxSize-1)
		{
			L->data[L->length] = L->length;
			L->length++;
		}
		return 1;
}


//给顺序表第i个位置插入一个元素e
bool ListInsert(SeqList* L, int i ,int value) {
	if (i < 1 || L->length >= MaxSize ) {
		printf("插入位置非法\n");
		return false;
	}

	if (L->length >= MaxSize) {
		printf("顺序表已满，无法插入数据\n");
		return false;
	}

	//i以后的元素后移
	for (int j = L->length; j >= i; j--)
		L->data[j] = L->data[j - 1];  //元素后移
	L->data[i - 1] = value;   //将元素插入到第i个位置
	L->length++;   //长度加一
	return true;
}

//删除顺序表第i个位置的元素e,并将e返回
bool ListDelet(SeqList*L, int i, int*e){
	if (i<1 || i>L->length) {  //判断i的范围是否有效
		printf("删除位置非法\n");
		return false;
	}
	*e = L->data[i - 1];
	for (int j = i; j < L->length; j++)  //将第i个位置后的元素前移
		L->data[j - 1] = L->data[j];
	L->length--;
	return true;
}


//打印顺序表
void PrintList(SeqList L) {
	if (L.length > MaxSize) {
		printf("线性表出错\n");
	}
	for (int i = 0; i < L.length; i++)
		printf("data[%d]=%d\n", i, L.data[i]);
}

int main()
{
	SeqList L;   //申明一个顺序表
	InitList(&L);

	L.data[0] = 30;
	L.length++;
	L.data[1] = 31;
	L.length++;
	L.data[2] = 33;
	L.length++;

	InsertData(&L);
	PrintList(L);   //打印顺序表
	printf("-----------------------------------------\n");
	ListInsert(&L, 8, 66);
	PrintList(L);   //打印顺序表

	printf("-----------------------------------------\n");
	int e = 0;
	ListDelet(&L, 2, &e);
	PrintList(L);   //打印顺序表
	printf("%d\n", e);
	return 0;
}