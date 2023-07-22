
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// ջ��Ӧ��--����ƥ��
// ��ͬ�����ű����˫�ɶ�
// ���������ž���ջ
// ���������ž� "����" һ��������

// IDE-���ǿ��ӻ��ı�̻���

// �㷨ʵ��
#define MaxSize 20
typedef struct {
    char data[MaxSize];  // ��̬������ջ��Ԫ��
    int top;             // ջ��ָ��
    int length;
} SqStack;

// ��ʼ��ջ
void InitStack(SqStack& S) {
    S.top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S) {
    return (S.top == -1);
}

// ��Ԫ����ջ
bool Push(SqStack& S, char x) {
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

// ��ջ����
bool Pop(SqStack& S, char& x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool brackCheck(SqStack& S, char str[], int length) {
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);  // ɨ�赽�����ţ���ջ
        }
        else {
            if (StackEmpty(S))  // ɨ�赽�������ҵ�ǰջΪ��
                return false;   // ƥ��ʧ�� 

            char topElem;
            Pop(S, topElem);  // ջ��Ԫ�س�ջ
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S);  // ������ȫ�����ź�ջ��˵��ƥ��ɹ�
}

int main() {
    SqStack S;
    InitStack(S);
    // �������˳���ֵ
    char arr[] = { '[', '{', '(', ')', '}', ']' };
    int size = sizeof(arr) / sizeof(arr[0]);

    S.length = size;

    bool isMatch = brackCheck(S, arr, size);

    if (brackCheck(S, arr, size)) {
        cout<< "����ƥ��ɹ���" <<endl;
    }
    else {
        cout << "����ƥ��ʧ�ܣ�" << endl;
    }

    return 0;
}