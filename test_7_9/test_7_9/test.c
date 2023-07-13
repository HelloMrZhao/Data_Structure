#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

////˳����ʵ��
////��̬˳���

//#define MaxSize 10           //�������Ա����󳤶�
//typedef struct {
//	ElemType data[MaxSize];  //�þ�̬�����������ݱ��Ԫ��
//	int length;              //˳���ĵ�ǰ����
//}Sqlist;                     //���ݱ������������̬����ķ�ʽ��



//��ʼ����̬˳���
//#include <stdio.h>
//#define MaxSize 10   //������󳤶�
//typedef struct {
//	int data[MaxSize];
//	int length;      //˳���ĵ�ǰ����
//}SqList;             //˳�������Ͷ���
//
////����������ʼ��һ��˳���
//void InitList(SqList L) {
//	for (int i = 0; i < MaxSize; i++)
//	    L.data[i] = 0;  //����������Ԫ������ΪĬ�ϳ�ʼֵ
//	    L.length = 0;     //˳�����Գ���Ϊ0
//}
//
//int main()
//{
//	SqList L;  //����һ��˳���
//	InitList(L); //��ʼ��һ��˳���
//	for (int i = 0; i < MaxSize; i++)
//		printf("data[%d]=%d\n", i, L.data[i]);
//	return 0;
//}




////��̬˳���
//#define InitSize 10  //˳���ĳ��Գ���
//typedef struct {
//	ElemType* data;  //ָ��̬���������ָ��
//	int MaxSize;     //˳�����������
//	int length;      //˳���ĵ�ǰ����
//}SeqList;            //˳�������Ͷ��壨��̬���䷽ʽ��
//
////Key:��̬������ͷ��ڴ�ռ�
////malloc��free����
////L.data = (ElemType)malloc(sizeof(ElemType) * InitSize);




//#include <stdlib.h>
//#include <stdio.h>
//#define MaxSize 10   //������󳤶�
//
//typedef struct {
//    int data[MaxSize];
//    int length;      //˳���ĵ�ǰ����
//}SeqList;             //˳�������Ͷ���
//
////����������ʼ��һ��˳���
//void InitList(SeqList *L) {
//    for (int i = 0; i < MaxSize; i++)
//        L->data[i] = 0;  //����������Ԫ������ΪĬ�ϳ�ʼֵ
//    L->length = 0;     //˳�����Գ���Ϊ0
//}
//
//void PrintList(SeqList  L) {
//    for (int i = 0; i < L.length; i++)
//        printf("data[%d]=%d\n", i, L.data[i]);
//}
//
//int main()
//{
//    SeqList L;  //����һ��˳���
//    InitList(&L); //��ʼ��һ��˳���
//    PrintList(L); //��ӡ˳�������
//    printf("Initialized a sequential list with length %d\n", L.length);
//    return 0;
//} 





//��̬˳���ĳ�ʼ����д��Ԫ�غʹ�ӡ
//��̬˳����ڵ�i��λ�ò���Ԫ��e
//��̬˳����ڵ�i��λ��ɾ��Ԫ��e,������e

#include <stdio.h>
#include< stdbool.h >
#define MaxSize 10
typedef struct  {
    int data[MaxSize];
    int length;
}SeqList;   //˳�������Ͷ���

//��ʼ��˳���
void InitList(SeqList *L)
{
    for (int i = 0; i < MaxSize; i++)
        L->data[i] = 0;
    L->length = 0;

}

//��˳���д������
int InsertData(SeqList* L)
{
    if (L->length >= MaxSize) {
        printf("˳����������޷���������");
        return 0;
    }
    for (int i = 0; i < MaxSize-1; i++)
    {
        L->data[i] = i;
        L->length++; //���ȼ�һ
    }
   

    return 1;
 }



//��ӡ˳���
void PrintList(SeqList L)
{
    printf("˳������ݣ�\n");
    for (int i = 0; i < L.length; i++)
        printf("data[%d]=%d \n", i, L.data[i]);
}

//�ڵ�i��λ�ò���Ԫ��
bool ListInsert(SeqList* L, int i, int value) {
    if (i < 1 || i > L->length + 1) {
        printf("����λ�÷Ƿ�\n");
        return false;
    }

    if (L->length >= MaxSize) {
        printf("˳����������޷���������\n");
        return false;
    }

    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];  //Ԫ�غ���
    }

    L->data[i - 1] = value; //��Ԫ�ز��뵽��i��λ��
    L->length++; //���ȼ�һ

    return true;
}

bool ListDelete(SeqList* L, int i, int*e)
{
    if (i<1 || i> L->length) {//�ж�i�ķ�Χ�Ƿ���Ч
        printf("ɾ��λ�÷Ƿ�\n");
        return false;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)  //����i��λ�ú��Ԫ��ǰ��
        L->data[j - 1] = L->data[j];
    L->length--;

    return true;
    
}

int main()
{
    SeqList L;  //����һ��˳���L
    InitList(&L);
    InsertData(&L);
    PrintList(L);
    ListInsert(&L, 3, 30);

    PrintList(L);

    int e = 0;
    ListDelete(&L,5,&e);

    printf("��ɾ����Ԫ��ֵ�ǣ�%d\n", e);
    PrintList(L);

    return 0;
}




