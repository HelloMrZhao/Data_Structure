#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>    
#include <stdlib.h>
//#define N 200
//typedef int SLDataType;
// double SLDataType; 
// char SLDataType; 


//��̬˳��� -- N̫С�����ܲ����ã�N̫�󣬿����˷ѿռ�
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};


typedef int SLDataType;
typedef struct SeqList
{
	SLDataType *a; //ָ��̬�����ָ��
	int size;  //���ݸ���
	int capacity; //����-�ռ��С
}SL;

void SLPrint(SL*ps);
//��ɾ���
//void SeqListInit(SL s) //��һ���ȶ�˳����ʼ�����������ʼ���Ϳ��������ֵ
void SLInit(SL* ps); //��һ���ȶ�˳����ʼ�����������ʼ���Ϳ��������ֵ

void SLCheckCapacity(SL* ps);

//ͷ��/ͷɾ/β��/βɾ
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLpopFront(SL* ps);

