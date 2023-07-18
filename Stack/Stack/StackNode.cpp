#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//
////��ջ
////����ʽ�洢��ʽʵ��ջ
//typedef struct Linknode {
//	int data;                //������
//	struct Linknode* next;   //ָ����
//}*LiStack;                   //վ���Ͷ���
//
//
////��ʼ��
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

// ջ�ڵ�Ľṹ
struct StackNode {
    int data;          // �ڵ�����
    struct StackNode* next;  // ָ����һ���ڵ��ָ��
};

// ջ�Ľṹ
struct LinkedStack {
    struct StackNode* top;   // ջ��ָ��
};

// ��ʼ��ջ
void InitStack(LinkedStack& stack) {
    stack.top = NULL;   // ��ջ��ָ����Ϊ��
}

// �ж�ջ��
bool StackEmpty(LinkedStack stack) {
    return (stack.top == NULL);   // ջΪ��ʱ����true�����򷵻�false
}

// ��ջ����
bool Push(LinkedStack& stack, int x) {
    // �����½ڵ�
    StackNode* newNode = ( StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        cout << "�ڴ����ʧ�ܣ�" << endl;
        return false;
    }
    // �ڵ㸳ֵ
    newNode->data = x;
    // �½ڵ��nextָ��ǰջ��Ԫ��
    newNode->next = stack.top;
    // ����ջ��ָ��
    stack.top = newNode;
    return true;
}

// ��ջ����
bool Pop(LinkedStack& stack, int& x) {
    if (stack.top == NULL) {
        cout << "ջΪ�գ�" << endl;
        return false;
    }
    // ��ȡջ��Ԫ��ֵ
    x = stack.top->data;
    // ���浱ǰջ���ڵ�
    StackNode* temp = stack.top;
    // ����ջ��ָ��Ϊ��һ���ڵ�
    stack.top = stack.top->next;
    // �ͷŵ�ǰջ���ڵ���ڴ�
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
    while (StackEmpty(stack)!= NULL) {   //ջ��Ϊ��ʱ����
        Pop(stack, x);
        cout << "����ջ��Ԫ�أ�" << x << endl;
    }
    return 0;
}