#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//�������Ľ�㣨��ʽ�洢��
typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

//�������������
typedef struct ThreadNode {
	int data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;   //����������־�����ltag=0����ʾ����ָ��ָ�����ӣ����ltag=1,���ʾ����ָ��ָ��ǰ��������ͬ�����rtag=1�����ʾ�Һ���ָ��䵱�������
}ThreadNode,*ThreadTree;