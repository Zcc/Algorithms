#include<iostream>
using namespace std;
typedef struct node
{
	int time;     //记录所选作业的总时间
	int parent;         //记录节点的父亲节点
	int x;     //记录所选的作业序号
	float u,c;   //u,c分别记录罚款上限和估计罚款
	int date;  //记录所选作业的最后截止期限
}F;F q[30];   //队列结构体数组
float p[10]={5,10,6,3};
int t[10]={1,2,1,1},d[10]={1,3,2,1},a[10]={0,1,2,3,4,5,6,7,8,9};
int i,j,D=4,k,E,b;
float co,up,max=1000,U,e=0.5;
F w[1];


int time(int k,int E)//判断当前所选作业时间是否冲突
{
	if(q[E].date <d[a[k]])
		w[0].date =d[a[k]];
	else w[0].date =q[E].date;
	if(q[E].time+t[a[k]]>w[0].date )
		return 0;
	else return 1;
}

void cost(int k,int E)//计算估计成本函数
{
	int m;
	if(!time(k,E))
		co=1000;
	else if(q[E].x-a[k]!=-1)
	{co=q[E].c;
	for(m=q[E].x+1;m<a[k];m++)
		co=co +p[m];
	}else co=q[E].c ;
	up=q[E].u -p[a[k]];
}

void enterq(int k,int E)//进队列的函数
{
	q[j].c=co;q[j].date =d[a[k]];
	q[j].parent =E;q[j].time =q[E].time +t[a[k]];
	q[j].u =up;q[j].x =a[k];
	if(q[j].u <U)
	{ U=q[j].u +e;b=j;}//记录答案节点
	j++;
}

int ynset()//判断队列是否为空
{
	if(i!=j)return 0;
	else return 1;
}

int outq()
{
	int t;
	t=i++;
	return t;
}


void FIFOBB(int E)//分枝限界函数
{
	int t;
	while(!ynset()||i==1)
	{ 
		for(k=q[E].x+1;k<D;k++)
		{
			cost(k,E);
			if(co<U)//判断估计成本是否小于罚款上限，如果是则进队列；否则出队列
				enterq(k,E);
		}
		E=outq();
	}
	{   printf("最小罚款：%f",U-e);
	printf("\n");
	printf("最优解为：%d",q[b].x+1);
	printf(" ");
	t=q[b].parent;
	while(q[t].parent !=-1)
	{
		printf("   %d",q[t].x+1 );
		printf("\n");
		t=q[t].parent;
	}
	}

}

void main()//主函数
{
	int i;
	cout<<"*********LC带限期作业排序***********"<<endl<<"罚款：";
	for(i = 0; i < D; i++)
	{cout<<p[i]<<" ";}
	cout<<endl<<"期限：";
	for(i = 0; i < D; i++)
		cout<<d[i]<<" ";
	cout<<endl<<"时间：";
	for(i = 0; i < D; i++)
		cout<<t[i]<<" ";
	cout<<endl;
	q[0].c =0;//初始化树的根节点
	q[0].u =24;
	q[0].date =0;
	q[0].time =0;
	q[0].parent =-1;
	q[0].x =-1;i=j=1;
	U=q[0].u +e;
	FIFOBB(0);

}
