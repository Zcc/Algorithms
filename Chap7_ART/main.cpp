#include <iostream>
using namespace std;
#define N 7

int num =1;
int ART(int u,int v,int E[N][N],int DFN[],int n)
{
	int L[N],w;
	DFN[u]=num;
	L[u]=num;
	num++;
	for(w=1;w<N;w++)
	{
		if(E[u][w]==1)
		{
			if(DFN[w]==0)
			{
				ART(w,u,E,DFN,n);
				if(L[w]<L[u])
				{
					L[u]=L[w];
				}
			}
			else if(w!=v)
			{
				if(DFN[w]<L[u])
				{
					L[u]=DFN[w];
				}
			}
		}
	}
	return 0;
}

int main()
{
    int E[7][7]={{0,0,0,0,0,0,0},{0,0,1,0,1,1,0},{0,1,0,1,0,1,1},{0,0,1,0,0,1,1},{0,1,0,0,0,0,1},{0,1,1,1,0,0,1},{0,0,1,1,1,1,0}};
	int DFN[7]={0,0,0,0,0,0,0},i,j;
	ART(1,6,E,DFN,6);
		cout<<"********计算DFN和L算法演示*********"<<endl<<"输入图的临接矩阵为："<<endl;
		for(i=1;i<=6;i++)
	{
		for(j=1;j<=6;j++)
		{

				cout<<E[i][j]<<" ";

		}
		cout<<endl;
	}
		cout<<"计算后的DFN值为："<<endl;
			for(i=1;i<=6;i++)
	{
		cout<<DFN[i]<<" ";
			}
			cout<<endl;
	return 0;
}