#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;

//#define MAXLEN 255  //预定义最大串长为255
//typedef struct {
//	char ch[MAXLEN];   //每个分量存储一个字符,(静态数组实现（定长顺序存储））
//	int length;        //串的实际长度
//}SString;
//
//
////用动态数组的方式来实现
//typedef struct {
//	char* ch;  //按串长分配存储区，ch指向串的基地址
//	int length;  //串的长度
//}HString;  //动态数组实现堆分配存储
//HString S;
//S.ch = (char*)malloc(MAXLEN * sizeof(cgar));
//S.length = 0;

////串的链式存储
//typedef struct StringNode {
//	char ch[4];
//	struct StringNode* next;
//}StringNode,*String;

//求子串
//SubString(&Sub,S,pos,len):求子串。用Sub返回串S的第pos个字符起长度为len的字串


#define MAXLEN 255  //预定义最大串长为255
typedef struct {
	char ch[MAXLEN];   //每个分量存储一个字符,(静态数组实现（定长顺序存储））
	int length;        //串的实际长度
}SString;

//求子串
bool SubString(SString& Sub, SString S, int pos, int len) {
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos + len; i++)
		Sub.ch[i - pos + 1] = S.ch[i];
	Sub.length = len;
	return true;
}


//两个字符串的比较操作
//StrCompare(S,T):比较操作。若S>T，则返回值>0;若S=T，则返回值=0；若S<T，则返回值<0。

//比较操作。若S>T,则返回值>0;若S=T，则返回值=0；若S<T,则返回值<0
int StrCompare(SString S, SString T) {
	for (int i = 1; i <= S.length && i <= T.length; i++) {
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	//扫描过的所有字符都相同，则长度长的串更大
	return S.length - T.length;
}

//定位操作index(S,T):定位操作。若主串S中存在与串T值相同的字串，返回它在主串S中第一次出现的位置：否则函数值为0.

int Index(SString S, SString T) {
	//int i = 1, n = StrLength(S), m = StrLenght(T);
	int i = 1, n = S.length, m = T.length;
	SString sub;    //用于暂存子 串
	while (i <= n - m + 1) {
		SubString(sub, S, i, m);
		if (StrCompare(sub, T) != 0)  ++i;
		else return i; //返回字串在主串中的位置
	}
	return 0;       //S中不存在与T相等的子串
}

//朴素模式匹配算法
int Index(SString S, SString T) {
	int i = 1, j = 1;
	while (i < S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			++i; ++j;    //继续比较后继字符
		}
		else {
			i = i - j + 2;
			j = 1;         //指针后退重新开始匹配
		}
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}


//KMP算法
int Index_KMP(SString S, SString T, int next[]) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			++i;
			++j;           //继续比后继模式串
		}
		else
			j = next[j];    //模式串向右移动
	}
	if (j > T.length)
		return i - T.length;   //匹配成功
	else
		return 0;
}

//求模式串的next数组
//next数组的作用：当模式串的第j个字符失配时，从模式串的第next[j]的位置继续往后匹配

//KMP算法优化
//求nextval数组
//先求next数组，再由next数组求nextval数组
nextval[1] = 0;
for (int j = 2; j <= T.length; j++) {
	if (T.ch[next[j]] == T.ch[j])
		nextval[j] = nextval[next[j]];
	else
		nextval[j] = next[j];
}


int main()
{
	 
	return 0;
}