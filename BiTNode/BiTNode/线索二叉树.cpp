#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//二叉树的结点（链式存储）
typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

//线索二叉树结点
typedef struct ThreadNode {
	int data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;   //左右线索标志，如果ltag=0，表示左孩子指针指向左孩子，如果ltag=1,则表示左孩子指针指向前驱线索，同理如果rtag=1，则表示右孩子指针充当后继线索
}ThreadNode,*ThreadTree;