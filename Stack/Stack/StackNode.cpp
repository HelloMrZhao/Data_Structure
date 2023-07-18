#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
////链栈
////用链式存储方式实现栈
//typedef struct Linknode {
//	int data;                //数据域
//	struct Linknode* next;   //指针域
//}*LiStack;                   //站类型定义
//
//
////初始化
//void InitLinknode(Linknode& L) {
//	L.next = NULL;
//}
//
//void textLinknode() {
//	Linknode L;
//	InitLinknode(L);
//}
//
//int main()
//{
//	system("pause");
//	return 0;
//}


#include <iostream>
#include <stdlib.h>
using namespace std;

// 栈节点的结构
struct StackNode {
    int data;          // 节点数据
    struct StackNode* next;  // 指向下一个节点的指针
};

// 栈的结构
struct LinkedStack {
    struct StackNode* top;   // 栈顶指针
};

// 初始化栈
void InitStack(LinkedStack& stack) {
    stack.top = NULL;   // 将栈顶指针置为空
}

// 判断栈空
bool StackEmpty(LinkedStack stack) {
    return (stack.top == NULL);   // 栈为空时返回true，否则返回false
}

// 进栈操作
bool Push(LinkedStack& stack, int x) {
    // 创建新节点
    StackNode* newNode = ( StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        cout << "内存分配失败！" << endl;
        return false;
    }
    // 节点赋值
    newNode->data = x;
    // 新节点的next指向当前栈顶元素
    newNode->next = stack.top;
    // 更新栈顶指针
    stack.top = newNode;
    return true;
}

// 出栈操作
bool Pop(LinkedStack& stack, int& x) {
    if (stack.top == NULL) {
        cout << "栈为空！" << endl;
        return false;
    }
    // 获取栈顶元素值
    x = stack.top->data;
    // 保存当前栈顶节点
    StackNode* temp = stack.top;
    // 更新栈顶指针为下一个节点
    stack.top = stack.top->next;
    // 释放当前栈顶节点的内存
    free(temp);
    return true;
}

int main() {
    LinkedStack stack;
    InitStack(stack);
    Push(stack, 5);
    Push(stack, 10);
    Push(stack, 15);
    int x;
    while (StackEmpty(stack)!= NULL) {   //栈不为空时成立
        Pop(stack, x);
        cout << "弹出栈顶元素：" << x << endl;
    }
    return 0;
}