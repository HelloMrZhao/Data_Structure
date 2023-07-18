#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
using namespace std;
 

//˳��ջ�Ķ���
#define MaxSize 10      //����ջ��Ԫ�ص�������
typedef struct {     
	int data[MaxSize];  //��̬������ջ��Ԫ��
	int top;            //ջ��ָ��
}SqStack;

//��ʼ��ջ
void InitStack(SqStack &S){
	S.top=-1;     ///��ʼ��ջ��ָ��
}

void tesStack() {
	SqStack S;     //����һ��˳��ջ������ռ䣩
	//����....
	InitStack(S);
}

//�ж�ջ��
bool StackEmpty(SqStack S){
	if (S.top == -1)       //ջ��
		return true;
	else                   //����
		return false;
}

//��ջ����
bool Push(SqStack &S, int x) {
	if (S.top == MaxSize - 1)   //ջ������
		return false;
	//S.top = S.top + 1;        //ָ���ȼ�1
	//S.data[S.top] = x;        //��Ԫ����ջ
	S.data[++S.top] = x;

	return true;
}

//��ջ����
bool Pop(SqStack &S, int &x) {
	if (S.top == -1) 
		return false;    //ջ�գ�����      
	//x = S.data[S.top];    //ջ��Ԫ���ȳ�ջ
	//S.top = S.top - 1;   //ָ���ڼ�1
	x = S.data[S.top--];
	return true; 
}

//��ȡջ��Ԫ�صĲ���
bool GetTop(SqStack S, int &x){
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

typedef struct {
	int data[MaxSize];
	int top0;  //0��ջջ��ָ��
	int top1;  //1��ջջ��ָ��
 }ShStack;


//����ջ
void InitStack(ShStack &S){
	S.top0 = -1;
	S.top1 = MaxSize;
}


void testShStack() {
	ShStack S;     //����һ��˳��ջ������ռ䣩
	//����....
	InitStack(S);
}
//��ջ����
bool Push(ShStack &S, int x,int y) {
	if (S.top1 == S.top0+1)   //ջ������
		return false;
	//S.top = S.top + 1;        //ָ���ȼ�1
	//S.data[S.top] = x;        //��Ԫ����ջ
	S.data[--S.top1] = x;
	S.data[++S.top0] = y;


	return true;
}



int main()
{
	system("pause");
	return 0;
}



