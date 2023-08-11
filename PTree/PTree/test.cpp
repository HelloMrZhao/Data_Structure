#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//1)先根遍历。若树非空，先访问根节点，在依次对每棵树进行先根遍历。

//树的先根遍历
//void PreOrder(TreeNode* R) {
//	if (R != NULL) {
//		visit(R);   //访问根节点
//		while (R还有下一个子树T)
//			PreOrder(T);   //先根遍历下一颗子树
//	}
//}

//



//树的后根遍历
//void PreOrder(TreeNode* R) {
//	if (R != NULL) {
//		while (R还有下一个子树T)
//			PostOrder(T);   //后根遍历下一颗子树
//		visit(R);   //访问根节点
// 
//	}
//}


//树的存储--双亲表示法
//双亲表示法：每个结点中保存指向双亲的“指针”
#define MAX_TREE_SIZE 100     //树中最多结点数
typedef struct {               //树的结点定义
	char data;                 //数据元素
	int parent;                //双亲位置域
}PTNode;
typedef struct{                //树的类型定义
	PTNode nodes[MAX_TREE_SIZE]; //双亲表示
	int n;                        //结点数
};

//集合的两个基本操作--“并”和“查”
//Find -- "查“操作：确定一个指定元素所属集合
//Union -- "并”操作：将两个不相交 的集合合并为一个

#define SIZE 13
int UFSets[SIZE];   //集合元素数组

//初始化并查集
void Initial(int S[]) {
	for (int i = 0; i < SIZE; i++)
		S[i] = -1;
}

//Find"查“操作，找x所属集合（返回x所属根结点）
int Find(int S[], int x) {
	while (S[x] >= 0)    //循环寻找x的根
		x = S[x];
	return x;          //根的s[]小于0
}

//Union "并”操作，将两个集合合并为一个
void Union(int S[], int Root1, int Root2) {
	//要求Root1与Root2是不同集合
	if (Root1 == Root2) return;
	if (S[Root2] > S[Root1]) { //Root2结点数更少
		S[Root1] += S[Root2]; //累加结点总数
		S[Root2] = Root1; //小树合并到大树
	}
	else {
		S[Root2] += S[Root1]; //累加结点总数
		S[Root1] = Root1; //小树合并到大树
	}
	//将根Root2连接到另一根Root1下面
	S[Root2] == Root1;
}

//Find操作的优化（压缩路径）
//Find"查“操作优化，先找到根节点，再进行”压缩路径“
int Find(int S[], int x) {
	int root = x;
	while (S[root] >= 0)  root = S[root]; //循环找到根
	while (x != root) { //压缩路径
		int t = S[x];  //t指向x的父节点
		S[x] = root;   //x直接挂到根节点下
		x = t;
	}
	return root;  //返回根节点编号
}
int main()
{

	return 0;
}