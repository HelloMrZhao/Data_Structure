#define _CRT_SECURE_NO_WARNINGS 1
//线性表
//线性表是n个具有相同特性的数据元素的有限序列。线性表示在实际中广泛使用的数据结构，常见的线性表：顺序表，链表，栈，队列，字符串...

//线性表在逻辑上是线性结构，是连续的一条线，但是物理结构不一定是线性的



//顺序表可以理解为数组

#include "SeqList.h"

void TestSeqList1()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(&sl);

	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLPushBack(&sl, 5);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 5);

	SLPrint(&sl);




}

int main()
{
	TestSeqList1();
	return 0;
}