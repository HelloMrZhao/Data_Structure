#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;

//#define MAXLEN 255  //Ԥ������󴮳�Ϊ255
//typedef struct {
//	char ch[MAXLEN];   //ÿ�������洢һ���ַ�,(��̬����ʵ�֣�����˳��洢����
//	int length;        //����ʵ�ʳ���
//}SString;
//
//
////�ö�̬����ķ�ʽ��ʵ��
//typedef struct {
//	char* ch;  //����������洢����chָ�򴮵Ļ���ַ
//	int length;  //���ĳ���
//}HString;  //��̬����ʵ�ֶѷ���洢
//HString S;
//S.ch = (char*)malloc(MAXLEN * sizeof(cgar));
//S.length = 0;

////������ʽ�洢
//typedef struct StringNode {
//	char ch[4];
//	struct StringNode* next;
//}StringNode,*String;

//���Ӵ�
//SubString(&Sub,S,pos,len):���Ӵ�����Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���ִ�


#define MAXLEN 255  //Ԥ������󴮳�Ϊ255
typedef struct {
	char ch[MAXLEN];   //ÿ�������洢һ���ַ�,(��̬����ʵ�֣�����˳��洢����
	int length;        //����ʵ�ʳ���
}SString;

//���Ӵ�
bool SubString(SString& Sub, SString S, int pos, int len) {
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos + len; i++)
		Sub.ch[i - pos + 1] = S.ch[i];
	Sub.length = len;
	return true;
}


//�����ַ����ıȽϲ���
//StrCompare(S,T):�Ƚϲ�������S>T���򷵻�ֵ>0;��S=T���򷵻�ֵ=0����S<T���򷵻�ֵ<0��

//�Ƚϲ�������S>T,�򷵻�ֵ>0;��S=T���򷵻�ֵ=0����S<T,�򷵻�ֵ<0
int StrCompare(SString S, SString T) {
	for (int i = 1; i <= S.length && i <= T.length; i++) {
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	//ɨ����������ַ�����ͬ���򳤶ȳ��Ĵ�����
	return S.length - T.length;
}

//��λ����index(S,T):��λ������������S�д����봮Tֵ��ͬ���ִ���������������S�е�һ�γ��ֵ�λ�ã�������ֵΪ0.

int Index(SString S, SString T) {
	//int i = 1, n = StrLength(S), m = StrLenght(T);
	int i = 1, n = S.length, m = T.length;
	SString sub;    //�����ݴ��� ��
	while (i <= n - m + 1) {
		SubString(sub, S, i, m);
		if (StrCompare(sub, T) != 0)  ++i;
		else return i; //�����ִ��������е�λ��
	}
	return 0;       //S�в�������T��ȵ��Ӵ�
}

//����ģʽƥ���㷨
int Index(SString S, SString T) {
	int i = 1, j = 1;
	while (i < S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			++i; ++j;    //�����ȽϺ���ַ�
		}
		else {
			i = i - j + 2;
			j = 1;         //ָ��������¿�ʼƥ��
		}
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}


//KMP�㷨
int Index_KMP(SString S, SString T, int next[]) {
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			++i;
			++j;           //�����Ⱥ��ģʽ��
		}
		else
			j = next[j];    //ģʽ�������ƶ�
	}
	if (j > T.length)
		return i - T.length;   //ƥ��ɹ�
	else
		return 0;
}

//��ģʽ����next����
//next��������ã���ģʽ���ĵ�j���ַ�ʧ��ʱ����ģʽ���ĵ�next[j]��λ�ü�������ƥ��

//KMP�㷨�Ż�
//��nextval����
//����next���飬����next������nextval����
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