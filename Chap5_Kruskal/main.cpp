 #include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()等
 #include<limits.h> // INT_MAX等
 #include<stdio.h> // EOF(=^Z或F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream> // cout,cin
 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 // #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行
 typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
 typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE

 // algo7-8.cpp 克鲁斯卡尔算法求无向连通网的最小生成树的程序
typedef int VRType;
typedef char InfoType;
#define MAX_NAME 3 // 顶点字符串的最大长度+1
#define MAX_INFO 20 // 相关信息字符串的最大长度+1
#define INFINITY INT_MAX // 用整型最大值代替∞
#define MAX_VERTEX_NUM 26 // 最大顶点个数

typedef char VertexType[MAX_NAME];
// #include"c7-1.h"
// #include"bo7-1.cpp"

// 图的数组(邻接矩阵)存储表示
enum GraphKind{DG,DN,UDG,UDN}; // {有向图,有向网,无向图,无向网}

typedef struct
{
	VRType adj; // 顶点关系类型。对无权图，用1(是)或0(否)表示相邻否；对带权图，则为权值
	InfoType *info; // 该弧相关信息的指针(可无)
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 二维数组

struct MGraph
{
	VertexType vexs[MAX_VERTEX_NUM]; // 顶点向量
	AdjMatrix arcs; // 邻接矩阵
	int vexnum,arcnum; // 图的当前顶点数和弧数
	GraphKind kind; // 图的种类标志
};

int LocateVex(MGraph G,VertexType u)
{ // 初始条件：图G存在，u和G中顶点有相同特征
	// 操作结果：若G中存在顶点u，则返回该顶点在图中位置；否则返回-1
	int i;
	for(i=0;i<G.vexnum;++i)
		if(strcmp(u,G.vexs[i])==0)
			return i;
		return -1;
}

void CreateUDN(MGraph &G)
{ // 采用数组(邻接矩阵)表示法，构造无向网G。算法7.2
	int i,j,k,w,IncInfo=0;
	char s[MAX_INFO];
	VertexType va,vb;
	printf("请输入无向网G的顶点数,边数：");
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum);
	printf("请输入%d个顶点的值(<%d个字符):\n",G.vexnum,MAX_NAME);
	for(i=0;i<G.vexnum;++i) // 构造顶点向量
		scanf("%s",G.vexs[i]);
	for(i=0;i<G.vexnum;++i) // 初始化邻接矩阵
		for(j=0;j<G.vexnum;++j)
		{
			G.arcs[i][j].adj=INFINITY; // 网
			G.arcs[i][j].info=NULL;
		}
		printf("请输入%d条边的顶点1 顶点2 权值(以空格作为间隔): \n",G.arcnum);
		for(k=0;k<G.arcnum;++k)
		{
			scanf("%s%s%d%*c",va,vb,&w); // %*c吃掉回车符
			i=LocateVex(G,va);
			j=LocateVex(G,vb);
			G.arcs[i][j].adj=G.arcs[j][i].adj=w; // 无向
			if(IncInfo)
			{
				printf("请输入该边的相关信息(<%d个字符): ",MAX_INFO);
				gets(s);
				w=strlen(s);
				if(w)
				{
					G.arcs[i][j].info=G.arcs[j][i].info=(char*)malloc((w+1)*sizeof(char));
					// 无向，两个指针指向同一个信息
					strcpy(G.arcs[i][j].info,s);
				}
			}
		}
		G.kind=UDN;
}

void Display(MGraph G)
{ // 输出邻接矩阵存储表示的图G
	int i,j;
	char s[7];
	switch(G.kind)
	{
	case DG: strcpy(s,"有向图");
		break;
	case DN: strcpy(s,"有向网");
		break;
	case UDG:strcpy(s,"无向图");
		break;
	case UDN:strcpy(s,"无向网");
	}
	printf("输入的图为: \n");

	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[i][j].adj==INFINITY)
				printf("  ∞");
			else
				printf("  %d",G.arcs[i][j].adj);
		}
		printf("\n");

	}
	for(i=0;i<G.vexnum;i++)
		if(G.kind<2) // 有向
		{
			for(j=0;j<G.vexnum;j++)
				if(G.arcs[i][j].info)
					printf("%5s %11s     %s\n",G.vexs[i],G.vexs[j],G.arcs[i][j].info);
		} // 加括号为避免if-else对配错
		else // 无向,输出上三角
			for(j=i+1;j<G.vexnum;j++)
				if(G.arcs[i][j].info)
					printf("%5s %11s     %s\n",G.vexs[i],G.vexs[j],G.arcs[i][j].info);
}

void kruskal(MGraph G)
{
	int set[MAX_VERTEX_NUM],i,j;
	int k=0,a=0,b=0,min=G.arcs[a][b].adj;
	for(i=0;i<G.vexnum;i++)
		set[i]=i; // 初态，各顶点分别属于各个集合
	printf("最小代价生成树的各条边为:\n");
	while(k<G.vexnum-1) // 最小生成树的边数小于顶点数-1
	{ // 寻找最小权值的边
		for(i=0;i<G.vexnum;++i)
			for(j=i+1;j<G.vexnum;++j) // 无向网，只在上三角查找
				if(G.arcs[i][j].adj<min)
				{
					min=G.arcs[i][j].adj; // 最小权值
					a=i; // 边的一个顶点
					b=j; // 边的另一个顶点
				}
				min=G.arcs[a][b].adj=INFINITY; // 删除上三角中该边，下次不再查找
				if(set[a]!=set[b]) // 边的两顶点不属于同一集合
				{
					printf("%s-%s\n",G.vexs[a],G.vexs[b]); // 输出该边
					k++; // 边数+1
					for(i=0;i<G.vexnum;i++)
						if(set[i]==set[b]) // 将顶点b所在集合并入顶点a集合中
							set[i]=set[a];
				}
	}
}

void main()
{
	MGraph g;
	CreateUDN(g); // 构造无向网g
	Display(g); // 输出无向网g
	kruskal(g); // 用克鲁斯卡尔算法输出g的最小生成树的各条边
}

