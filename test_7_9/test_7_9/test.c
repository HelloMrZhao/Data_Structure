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

#include <stdio.h>
#define MaxSize 10   //������󳤶�

typedef struct {
    int data[MaxSize];
    int length;      //˳���ĵ�ǰ����
}SqList;             //˳�������Ͷ���

//����������ʼ��һ��˳���
void InitList(SqList L) {
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0;  //����������Ԫ������ΪĬ�ϳ�ʼֵ
    L.length = 0;     //˳�����Գ���Ϊ0
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++)
        printf("data[%d]=%d\n", i, L.data[i]);
}

int main()
{
    SqList L;  //����һ��˳���
    InitList(L); //��ʼ��һ��˳���
    PrintList(L); //��ӡ˳�������
    return 0;
}