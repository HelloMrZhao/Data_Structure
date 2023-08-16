#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//......准备工作，根据图的信息初始化矩阵A和矩阵path
//for (int k = 0; k < n; k++)     //考虑以Vk为中转点
//	for (int i = 0; i < n; i++){    //遍历整个矩阵，i为行号，j为列号
//		for (int j = 0; j < n; j++){
//			if (A[i][j] > A[i][k] + A[k][j]) {      //以Vk为中砖点的路径更短
//				A[i][j] = A[i][k] + A[k][j];   //更新最新路径长度
//				path[i][j] = k;   //中转点
//			}
//		}
//	}
//}

////逆拓扑排序的实现（DFS算法）
//void DFSTraverse(Graph G) {   //对图G进行深度优先遍历
//	for(v = 0; v = G.vexnum; v++)
//		visited[v] = FALSE;   //初始化以访问标记数据
//	for (v = 0; v < G.vexnum; ++v)  //本代码是从v=0开始遍历
//		if (!visited[v])
//			DFS(G, v);
//}
//void DFS(Graph G, int v) {  //从顶点v出发，深度优先遍历图G
//	visited[v] = TRUE;    //设以访问标记
//	for(w=FirstNeighbor(G,v);w>=0;w=NextNeighor(G,v,w))
//		if (!visited[w]) {  //w为u的尚未访问的邻接顶点
//			DFS(G, w);
//		}    //if
//	print(V);      //输出顶点,DFS实现逆拓扑排序：在顶点退栈前输出
//}



int main()
{
	return 0;
}
