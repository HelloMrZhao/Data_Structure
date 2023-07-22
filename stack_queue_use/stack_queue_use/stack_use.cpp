
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// 栈的应用--括号匹配
// 相同的括号必须成双成对
// 遇到左括号就入栈
// 遇到右括号就 "消耗" 一个左括号

// IDE-就是可视化的编程环境

// 算法实现
#define MaxSize 20
typedef struct {
    char data[MaxSize];  // 静态数组存放栈中元素
    int top;             // 栈顶指针
    int length;
} SqStack;

// 初始化栈
void InitStack(SqStack& S) {
    S.top = -1;
}

// 判断栈是否为空
bool StackEmpty(SqStack S) {
    return (S.top == -1);
}

// 新元素入栈
bool Push(SqStack& S, char x) {
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

// 出栈操作
bool Pop(SqStack& S, char& x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool brackCheck(SqStack& S, char str[], int length) {
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);  // 扫描到左括号，入栈
        }
        else {
            if (StackEmpty(S))  // 扫描到右括号且当前栈为空
                return false;   // 匹配失败 

            char topElem;
            Pop(S, topElem);  // 栈顶元素出栈
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S);  // 检索完全部括号后，栈空说明匹配成功
}

int main() {
    SqStack S;
    InitStack(S);
    // 用数组给顺序表赋值
    char arr[] = { '[', '{', '(', ')', '}', ']' };
    int size = sizeof(arr) / sizeof(arr[0]);

    S.length = size;

    bool isMatch = brackCheck(S, arr, size);

    if (brackCheck(S, arr, size)) {
        cout<< "括号匹配成功！" <<endl;
    }
    else {
        cout << "括号匹配失败！" << endl;
    }

    return 0;
}