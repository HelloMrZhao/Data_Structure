#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;


//��������˳��洢

//������Ҫ�����Ļ���������
//i������ --2i
//i���Һ��� --2i+1
//i�ĸ��ڵ� --[i/2]
//i���ڵĲ��  --ȡ��[log2(n+1)]��ȡ��[log2n]+1

//����ȫ�������й���n����㣬��
//�ж�i�Ƿ������ӣ� -- 2i <= n��
//�ж�i�Ƿ����Һ��ӣ� -- 2i + 1 <= n?
//�ж�i�Ƿ���Ҷ��/��֧��㣿 --i > ȡ��[n/2]?
#define MaxSize 100
struct TreeNode {
	int value; //�ڵ��е�����Ԫ��
	bool isEmpty; //����Ƿ�Ϊ��
};
TreeNode t[MaxSize];
//����һ������ΪMaxSize������t�����մ��ϵ��¡��������ҵ�˳�����δ洢��ȫ���������еĸ������

//��ʼ�����н����Ϊ��
bool InitTree(TreeNode T) {
	for (int i = 0; i < MaxSize; i++) {
		t[i].isEmpty = true;
	}
}




//����������ʽ�洢
//�������Ľ�㣨��ʽ�洢��
struct ElemType {
	int value;    //ÿ������Ԫ���������һ��int�͵ı���
};

typedef struct BiTNode {
	int data;      //������
	struct BiTNode* lchild, *rchild;   //���Һ���ָ��
}BiTNode,*BiTree;


//����һ�ſ���
BiTree root = NULL;

//������ڵ�
void InsertRootNode(BiTree) {
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data = { 1 };
	root->lchild = NULL;
	root->rchild = NULL;
}


//�����½ڵ�
void InsertNewNode(BiTNode) {
	BiTNode*p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = { 2 };
	p->rchild = NULL;
	root->lchild = p;   //��Ϊ���ڵ������
}



int main()
{
	struct TreeNode T;
	return 0;
}


//��������---�����Ҹ��ڵ�
//�������Ľ�㣨��ʽ�洢��
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, * echild;  //���Һ���ָ��
	struct BiTNode* parent;  //���ڵ�ָ��
}BiTNode,*BiTree;