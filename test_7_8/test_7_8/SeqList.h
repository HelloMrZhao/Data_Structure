#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>    
#include <stdlib.h>
//#define N 200
//typedef int SLDataType;
// double SLDataType; 
// char SLDataType; 


//静态顺序表 -- N太小，可能不够用，N太大，可能浪费空间
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};


typedef int SLDataType;
typedef struct SeqList
{
	SLDataType *a; //指向动态数组的指针
	int size;  //数据个数
	int capacity; //容量-空间大小
}SL;

void SLPrint(SL*ps);
//增删查改
//void SeqListInit(SL s) //第一步先对顺序表初始化，如果不初始化就可能是随机值
void SLInit(SL* ps); //第一步先对顺序表初始化，如果不初始化就可能是随机值

void SLCheckCapacity(SL* ps);

//头插/头删/尾插/尾删
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLpopFront(SL* ps);

