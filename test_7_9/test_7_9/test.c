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




//#include <stdlib.h>
//#include <stdio.h>
//#define MaxSize 10   //定义最大长度
//
//typedef struct {
//    int data[MaxSize];
//    int length;      //顺序表的当前长度
//}SeqList;             //顺序表的类型定义
//
////基本操作初始化一个顺序表
//void InitList(SeqList *L) {
//    for (int i = 0; i < MaxSize; i++)
//        L->data[i] = 0;  //将所有数据元素设置为默认初始值
//    L->length = 0;     //顺序表初试长度为0
//}
//
//void PrintList(SeqList  L) {
//    for (int i = 0; i < L.length; i++)
//        printf("data[%d]=%d\n", i, L.data[i]);
//}
//
//int main()
//{
//    SeqList L;  //声明一个顺序表
//    InitList(&L); //初始化一个顺序表
//    PrintList(L); //打印顺序表内容
//    printf("Initialized a sequential list with length %d\n", L.length);
//    return 0;
//} 





//静态顺序表的初始化、写入元素和打印
//静态顺序表在第i个位置插入元素e
//静态顺序表在第i个位置删除元素e,并返回e

#include <stdio.h>
#include< stdbool.h >
#define MaxSize 10
typedef struct  {
    int data[MaxSize];
    int length;
}SeqList;   //顺序表的类型定义

//初始化顺序表
void InitList(SeqList *L)
{
    for (int i = 0; i < MaxSize; i++)
        L->data[i] = 0;
    L->length = 0;

}

//给顺序表写入数据
int InsertData(SeqList* L)
{
    if (L->length >= MaxSize) {
        printf("顺序表已满，无法插入数据");
        return 0;
    }
    for (int i = 0; i < MaxSize-1; i++)
    {
        L->data[i] = i;
        L->length++; //长度加一
    }
   

    return 1;
 }



//打印顺序表
void PrintList(SeqList L)
{
    printf("顺序表内容：\n");
    for (int i = 0; i < L.length; i++)
        printf("data[%d]=%d \n", i, L.data[i]);
}

//在第i个位置插入元素
bool ListInsert(SeqList* L, int i, int value) {
    if (i < 1 || i > L->length + 1) {
        printf("插入位置非法\n");
        return false;
    }

    if (L->length >= MaxSize) {
        printf("顺序表已满，无法插入数据\n");
        return false;
    }

    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];  //元素后移
    }

    L->data[i - 1] = value; //将元素插入到第i个位置
    L->length++; //长度加一

    return true;
}

bool ListDelete(SeqList* L, int i, int*e)
{
    if (i<1 || i> L->length) {//判断i的范围是否有效
        printf("删除位置非法\n");
        return false;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)  //将第i个位置后的元素前移
        L->data[j - 1] = L->data[j];
    L->length--;

    return true;
    
}

int main()
{
    SeqList L;  //申请一个顺序表L
    InitList(&L);
    InsertData(&L);
    PrintList(L);
    ListInsert(&L, 3, 30);

    PrintList(L);

    int e = 0;
    ListDelete(&L,5,&e);

    printf("已删除的元素值是：%d\n", e);
    PrintList(L);

    return 0;
}




