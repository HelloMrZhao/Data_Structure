#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;


//二叉树的顺序存储

//几个重要常考的基本操作：
//i的左孩子 --2i
//i的右孩子 --2i+1
//i的父节点 --[i/2]
//i所在的层次  --取上[log2(n+1)]或取下[log2n]+1

//若完全二叉树中共有n个结点，则
//判断i是否有左孩子？ -- 2i <= n？
//判断i是否有右孩子？ -- 2i + 1 <= n?
//判断i是否是叶子/分支结点？ --i > 取下[n/2]?
#define MaxSize 100
struct TreeNode {
	int value; //节点中的数据元素
	bool isEmpty; //结点是否为空
};
TreeNode t[MaxSize];
//定义一个长度为MaxSize的数组t，按照从上到下、从左至右的顺序依次存储完全而二叉树中的各个结点

//初始化所有结点标记为空
bool InitTree(TreeNode T) {
	for (int i = 0; i < MaxSize; i++) {
		t[i].isEmpty = true;
	}
}




//二叉树的链式存储
//二叉树的结点（链式存储）
struct ElemType {
	int value;    //每个数据元素里面包含一个int型的变量
};

typedef struct BiTNode {
	int data;      //数据域
	struct BiTNode* lchild, *rchild;   //左、右孩子指针
}BiTNode,*BiTree;


//定义一颗空树
BiTree root = NULL;

//插入根节点
void InsertRootNode(BiTree) {
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data = { 1 };
	root->lchild = NULL;
	root->rchild = NULL;
}


//插入新节点
void InsertNewNode(BiTNode) {
	BiTNode*p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = { 2 };
	p->rchild = NULL;
	root->lchild = p;   //作为根节点的左孩子
}



int main()
{
	struct TreeNode T;
	return 0;
}


//三叉链表---方便找父节点
//二叉树的结点（链式存储）
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, * echild;  //左右孩子指针
	struct BiTNode* parent;  //父节点指针
}BiTNode,*BiTree;