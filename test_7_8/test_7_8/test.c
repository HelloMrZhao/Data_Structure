#define _CRT_SECURE_NO_WARNINGS 1
//���Ա�
//���Ա���n��������ͬ���Ե�����Ԫ�ص��������С����Ա�ʾ��ʵ���й㷺ʹ�õ����ݽṹ�����������Ա�˳�������ջ�����У��ַ���...

//���Ա����߼��������Խṹ����������һ���ߣ���������ṹ��һ�������Ե�



//˳���������Ϊ����

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