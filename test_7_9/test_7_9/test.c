#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////顺序表的实现
////静态顺序表

//#define MaxSize 10           //定义线性表的最大长度
//typedef struct {
//	ElemType data[MaxSize];  //用静态的数组存放数据表的元素
//	int length;              //顺序表的当前长度
//}Sqlist;                     //数据表的类型名（静态分配的方式）



//初始化静态顺序表
//#include <stdio.h>
//#define MaxSize 10   //定义最大长度
//typedef struct {
//	int data[MaxSize];
//	int length;      //顺序表的当前长度
//}SqList;             //顺序表的类型定义
//
////基本操作初始化一个顺序表
//void InitList(SqList L) {
//	for (int i = 0; i < MaxSize; i++)
//	    L.data[i] = 0;  //将所有数据元素设置为默认初始值
//	    L.length = 0;     //顺序表初试长度为0
//}
//
//int main()
//{
//	SqList L;  //声明一个顺序表
//	InitList(L); //初始化一个顺序表
//	for (int i = 0; i < MaxSize; i++)
//		printf("data[%d]=%d\n", i, L.data[i]);
//	return 0;
//}




////动态顺序表
//#define InitSize 10  //顺序表的初试长度
//typedef struct {
//	ElemType* data;  //指向动态分配数组的指针
//	int MaxSize;     //顺序表的最大容量
//	int length;      //顺序表的当前长度
//}SeqList;            //顺序表的类型定义（动态分配方式）
//
////Key:动态申请和释放内存空间
////malloc、free函数
////L.data = (ElemType)malloc(sizeof(ElemType) * InitSize);

#include <stdio.h>
#define MaxSize 10   //定义最大长度

typedef struct {
    int data[MaxSize];
    int length;      //顺序表的当前长度
}SqList;             //顺序表的类型定义

//基本操作初始化一个顺序表
void InitList(SqList L) {
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0;  //将所有数据元素设置为默认初始值
    L.length = 0;     //顺序表初试长度为0
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++)
        printf("data[%d]=%d\n", i, L.data[i]);
}

int main()
{
    SqList L;  //声明一个顺序表
    InitList(L); //初始化一个顺序表
    PrintList(L); //打印顺序表内容
    return 0;
}