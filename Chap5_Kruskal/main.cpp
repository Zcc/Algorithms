 #include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()��
 #include<limits.h> // INT_MAX��
 #include<stdio.h> // EOF(=^Z��F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream> // cout,cin
 // �������״̬����
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 // #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������
 typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
 typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE

 // algo7-8.cpp ��³˹�����㷨��������ͨ������С�������ĳ���
typedef int VRType;
typedef char InfoType;
#define MAX_NAME 3 // �����ַ�������󳤶�+1
#define MAX_INFO 20 // �����Ϣ�ַ�������󳤶�+1
#define INFINITY INT_MAX // ���������ֵ�����
#define MAX_VERTEX_NUM 26 // ��󶥵����

typedef char VertexType[MAX_NAME];
// #include"c7-1.h"
// #include"bo7-1.cpp"

// ͼ������(�ڽӾ���)�洢��ʾ
enum GraphKind{DG,DN,UDG,UDN}; // {����ͼ,������,����ͼ,������}

typedef struct
{
	VRType adj; // �����ϵ���͡�����Ȩͼ����1(��)��0(��)��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ
	InfoType *info; // �û������Ϣ��ָ��(����)
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // ��ά����

struct MGraph
{
	VertexType vexs[MAX_VERTEX_NUM]; // ��������
	AdjMatrix arcs; // �ڽӾ���
	int vexnum,arcnum; // ͼ�ĵ�ǰ�������ͻ���
	GraphKind kind; // ͼ�������־
};

int LocateVex(MGraph G,VertexType u)
{ // ��ʼ������ͼG���ڣ�u��G�ж�������ͬ����
	// �����������G�д��ڶ���u���򷵻ظö�����ͼ��λ�ã����򷵻�-1
	int i;
	for(i=0;i<G.vexnum;++i)
		if(strcmp(u,G.vexs[i])==0)
			return i;
		return -1;
}

void CreateUDN(MGraph &G)
{ // ��������(�ڽӾ���)��ʾ��������������G���㷨7.2
	int i,j,k,w,IncInfo=0;
	char s[MAX_INFO];
	VertexType va,vb;
	printf("������������G�Ķ�����,������");
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum);
	printf("������%d�������ֵ(<%d���ַ�):\n",G.vexnum,MAX_NAME);
	for(i=0;i<G.vexnum;++i) // ���춥������
		scanf("%s",G.vexs[i]);
	for(i=0;i<G.vexnum;++i) // ��ʼ���ڽӾ���
		for(j=0;j<G.vexnum;++j)
		{
			G.arcs[i][j].adj=INFINITY; // ��
			G.arcs[i][j].info=NULL;
		}
		printf("������%d���ߵĶ���1 ����2 Ȩֵ(�Կո���Ϊ���): \n",G.arcnum);
		for(k=0;k<G.arcnum;++k)
		{
			scanf("%s%s%d%*c",va,vb,&w); // %*c�Ե��س���
			i=LocateVex(G,va);
			j=LocateVex(G,vb);
			G.arcs[i][j].adj=G.arcs[j][i].adj=w; // ����
			if(IncInfo)
			{
				printf("������ñߵ������Ϣ(<%d���ַ�): ",MAX_INFO);
				gets(s);
				w=strlen(s);
				if(w)
				{
					G.arcs[i][j].info=G.arcs[j][i].info=(char*)malloc((w+1)*sizeof(char));
					// ��������ָ��ָ��ͬһ����Ϣ
					strcpy(G.arcs[i][j].info,s);
				}
			}
		}
		G.kind=UDN;
}

void Display(MGraph G)
{ // ����ڽӾ���洢��ʾ��ͼG
	int i,j;
	char s[7];
	switch(G.kind)
	{
	case DG: strcpy(s,"����ͼ");
		break;
	case DN: strcpy(s,"������");
		break;
	case UDG:strcpy(s,"����ͼ");
		break;
	case UDN:strcpy(s,"������");
	}
	printf("�����ͼΪ: \n");

	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[i][j].adj==INFINITY)
				printf("  ��");
			else
				printf("  %d",G.arcs[i][j].adj);
		}
		printf("\n");

	}
	for(i=0;i<G.vexnum;i++)
		if(G.kind<2) // ����
		{
			for(j=0;j<G.vexnum;j++)
				if(G.arcs[i][j].info)
					printf("%5s %11s     %s\n",G.vexs[i],G.vexs[j],G.arcs[i][j].info);
		} // ������Ϊ����if-else�����
		else // ����,���������
			for(j=i+1;j<G.vexnum;j++)
				if(G.arcs[i][j].info)
					printf("%5s %11s     %s\n",G.vexs[i],G.vexs[j],G.arcs[i][j].info);
}

void kruskal(MGraph G)
{
	int set[MAX_VERTEX_NUM],i,j;
	int k=0,a=0,b=0,min=G.arcs[a][b].adj;
	for(i=0;i<G.vexnum;i++)
		set[i]=i; // ��̬��������ֱ����ڸ�������
	printf("��С�����������ĸ�����Ϊ:\n");
	while(k<G.vexnum-1) // ��С�������ı���С�ڶ�����-1
	{ // Ѱ����СȨֵ�ı�
		for(i=0;i<G.vexnum;++i)
			for(j=i+1;j<G.vexnum;++j) // ��������ֻ�������ǲ���
				if(G.arcs[i][j].adj<min)
				{
					min=G.arcs[i][j].adj; // ��СȨֵ
					a=i; // �ߵ�һ������
					b=j; // �ߵ���һ������
				}
				min=G.arcs[a][b].adj=INFINITY; // ɾ���������иñߣ��´β��ٲ���
				if(set[a]!=set[b]) // �ߵ������㲻����ͬһ����
				{
					printf("%s-%s\n",G.vexs[a],G.vexs[b]); // ����ñ�
					k++; // ����+1
					for(i=0;i<G.vexnum;i++)
						if(set[i]==set[b]) // ������b���ڼ��ϲ��붥��a������
							set[i]=set[a];
				}
	}
}

void main()
{
	MGraph g;
	CreateUDN(g); // ����������g
	Display(g); // ���������g
	kruskal(g); // �ÿ�³˹�����㷨���g����С�������ĸ�����
}

