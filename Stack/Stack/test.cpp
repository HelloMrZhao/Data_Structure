#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
using namespace std;
 

//顺序栈的定义
#define MaxSize 10      //定义栈中元素的最大个数
typedef struct {     
	int data[MaxSize];  //静态数组存放栈中元素
	int top;            //栈顶指针
}SqStack;

//初始化栈
void InitStack(SqStack &S){
	S.top=-1;     ///初始化栈顶指针
}

void tesStack() {
	SqStack S;     //申明一个顺序栈（分配空间）
	//后续....
	InitStack(S);
}

//判断栈空
bool StackEmpty(SqStack S){
	if (S.top == -1)       //栈空
		return true;
	else                   //不空
		return false;
}

//进栈操作
bool Push(SqStack &S, int x) {
	if (S.top == MaxSize - 1)   //栈满报错
		return false;
	//S.top = S.top + 1;        //指针先加1
	//S.data[S.top] = x;        //新元素入栈
	S.data[++S.top] = x;

	return true;
}

//出栈操作
bool Pop(SqStack &S, int &x) {
	if (S.top == -1) 
		return false;    //栈空，报错      
	//x = S.data[S.top];    //栈顶元素先出栈
	//S.top = S.top - 1;   //指针在减1
	x = S.data[S.top--];
	return true; 
}

//读取栈顶元素的操作
bool GetTop(SqStack S, int &x){
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

typedef struct {
	int data[MaxSize];
	int top0;  //0号栈栈顶指针
	int top1;  //1号栈栈顶指针
 }ShStack;


//共享栈
void InitStack(ShStack &S){
	S.top0 = -1;
	S.top1 = MaxSize;
}


void testShStack() {
	ShStack S;     //申明一个顺序栈（分配空间）
	//后续....
	InitStack(S);
}
//进栈操作
bool Push(ShStack &S, int x,int y) {
	if (S.top1 == S.top0+1)   //栈满报错
		return false;
	//S.top = S.top + 1;        //指针先加1
	//S.data[S.top] = x;        //新元素入栈
	S.data[--S.top1] = x;
	S.data[++S.top0] = y;


	return true;
}



int main()
{
	system("pause");
	return 0;
}



