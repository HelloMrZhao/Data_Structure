#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>
using namespace std;

//静态链表

//单链表：各个结点在内存中星罗棋布、散落天涯
//静态链表：分配一整片连续的内存空间，各个节点集中安置
#define MaxSize 10 //静态链表的最大长度
struct Node {  // 静态链表结构类型的定义
	int data;
	int next;
};

typedef struct {      //静态链表结构类型的定义
	int data;      //存储数据元素
	int next;      //每个结点里包含了一个数据元素data,还包含了下一个元素的数组下标
}SLinkList[MaxSize];

//typedef struct Node SLinkList[MaxSize]; //可用SLinkList定义“一个长度为MaxSize的Node型数组”

void testSLinkList() {
	struct Node x;
	std::cout << "sizeX=" << sizeof(x) << std::endl;

	struct Node a[MaxSize];
	std::cout << "sizeA=" << sizeof(a) << std::endl;

	SLinkList b;
	std::cout << "sizeB=" << sizeof(b) << std::endl;
}

////用数组的方式来定义静态链表
//void testSLinkList() {
//	struct Node a[MaxSize];   //数组a作为静态链表
//	//....后续代码
//
//}
//
//void testSLinkList() {
//	//SLinkList a;
//	struct Node a[MaxSize];
//}

//初始化静态链表：
//把a[0]的next设为-1

//查找：
//从头结点出发挨个往后遍历结点

//插入位序位i的结点：
//1.找到一个空结点，存入数据元素 //如何判断结点是否为空？ //可以让next为某个特殊值，如-2
//2.从头结点出发找到位序为i-1的结点
//3.修改新结点的next
//4.修改i-1号结点的next


//删除某个结点：
//1.从头结点出发找到前驱结点
//2.修改前驱结点的游标
//3.被删除结点next设为 -2


//静态链表：用数组的方式实现链表

//优点：增、删操作不需要大量移动元素
//缺点：不能随机存取，只能从头结点开始依次往后查找；容量固定不变

//适用场景：1.不支持指针的低级语言；2.数据元素量固定不变的场景（如操作系统的文件分配表FAT）
int main()
{
	testSLinkList();
	return 0;
}



//章节总结
//顺序表和链表
//0.逻辑结构上：
// .....
//1.存储结构上：
//顺序表--（顺序存储）
//优点：支持随机存取、存储密度高
//缺点：大量连续空间分配不方便，改变容量不方便

//链表--（链式存储）
//优点：离散的小空间分配方便，改变容量方便
//缺点：不可随机存取，存储密度低

//2.基本操作
//顺序表---
//静态分配：静态数组，系统会自动回收空间
//动态分配：动态数组（malloc、free)，需要手动free释放空间
//L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
//free(L.data);


//链表---
//依次删除各个结点（free）

//用顺序表还是链表

//顺序表的强点就是--查
//链表的强点就是--弹性（可扩张）、增、删

//如果表长难以预估、经常要增加/删除元素    --链表
//比如开发一个小程序让他实现排队取号叫号的功能


//表长可预估、查询（搜索)操作较多   --顺序表
//实现课堂点名这样的功能可以用



//问题：顺序表和链表哪个好
//  顺序表和链表的逻辑结构都是线性结构，都属于线性表。
//但是二者的存储结构不同，顺序表采用顺序存储....(特点，带来的优缺点）；链表采用链式 存储（优点、缺点）。
//由于采用不同的存储方式实现，因此基本操作的实现效率也不同。当初始化时....;当插入一个数据元素时...;当删除一个数据元素时...;当查找一个数据元素时....;