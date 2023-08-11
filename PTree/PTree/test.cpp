#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//1)�ȸ������������ǿգ��ȷ��ʸ��ڵ㣬�����ζ�ÿ���������ȸ�������

//�����ȸ�����
//void PreOrder(TreeNode* R) {
//	if (R != NULL) {
//		visit(R);   //���ʸ��ڵ�
//		while (R������һ������T)
//			PreOrder(T);   //�ȸ�������һ������
//	}
//}

//



//���ĺ������
//void PreOrder(TreeNode* R) {
//	if (R != NULL) {
//		while (R������һ������T)
//			PostOrder(T);   //���������һ������
//		visit(R);   //���ʸ��ڵ�
// 
//	}
//}


//���Ĵ洢--˫�ױ�ʾ��
//˫�ױ�ʾ����ÿ������б���ָ��˫�׵ġ�ָ�롱
#define MAX_TREE_SIZE 100     //�����������
typedef struct {               //���Ľ�㶨��
	char data;                 //����Ԫ��
	int parent;                //˫��λ����
}PTNode;
typedef struct{                //�������Ͷ���
	PTNode nodes[MAX_TREE_SIZE]; //˫�ױ�ʾ
	int n;                        //�����
};

//���ϵ�������������--�������͡��顱
//Find -- "�顰������ȷ��һ��ָ��Ԫ����������
//Union -- "�������������������ཻ �ļ��Ϻϲ�Ϊһ��

#define SIZE 13
int UFSets[SIZE];   //����Ԫ������

//��ʼ�����鼯
void Initial(int S[]) {
	for (int i = 0; i < SIZE; i++)
		S[i] = -1;
}

//Find"�顰��������x�������ϣ�����x��������㣩
int Find(int S[], int x) {
	while (S[x] >= 0)    //ѭ��Ѱ��x�ĸ�
		x = S[x];
	return x;          //����s[]С��0
}

//Union "�������������������Ϻϲ�Ϊһ��
void Union(int S[], int Root1, int Root2) {
	//Ҫ��Root1��Root2�ǲ�ͬ����
	if (Root1 == Root2) return;
	if (S[Root2] > S[Root1]) { //Root2���������
		S[Root1] += S[Root2]; //�ۼӽ������
		S[Root2] = Root1; //С���ϲ�������
	}
	else {
		S[Root2] += S[Root1]; //�ۼӽ������
		S[Root1] = Root1; //С���ϲ�������
	}
	//����Root2���ӵ���һ��Root1����
	S[Root2] == Root1;
}

//Find�������Ż���ѹ��·����
//Find"�顰�����Ż������ҵ����ڵ㣬�ٽ��С�ѹ��·����
int Find(int S[], int x) {
	int root = x;
	while (S[root] >= 0)  root = S[root]; //ѭ���ҵ���
	while (x != root) { //ѹ��·��
		int t = S[x];  //tָ��x�ĸ��ڵ�
		S[x] = root;   //xֱ�ӹҵ����ڵ���
		x = t;
	}
	return root;  //���ظ��ڵ���
}
int main()
{

	return 0;
}