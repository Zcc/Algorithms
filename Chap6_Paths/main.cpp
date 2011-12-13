#include<iostream>
using namespace std;
#define ∞ 500

void All_Paths(int Cost[7][7],int A[7][7],int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			A[i][j]=Cost[i][j];
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				A[i][j]=(A[i][j]>(A[i][k]+A[k][j]))?(A[i][k]+A[k][j]):A[i][j];
			}
		}
	}
}

int main()
{
	int COST[7][7]={{∞,∞,∞,∞,∞,∞,∞},{67,∞,10,∞,30,45,∞},{∞,10,∞,50,∞,40,25},{∞,67,10,∞,∞,35,15},{∞,30,∞,∞,45,∞,20},{∞,45,40,35,∞,∞,23},{∞,∞,15,15,20,55,∞}};
	int A[7][7],i,j;
	All_Paths(COST,A,6);
		cout<<"****************图中每个节点之间的最短路径长度**************************"<<endl<<"原图的邻接矩阵为："<<endl;
		for(i=1;i<=6;i++)
	{
		for(j=1;j<=6;j++)
		{
			if(COST[i][j]==∞)
			{
				cout<<"∞ ";
			}
			else
			{
				cout<<COST[i][j]<<" ";
			}
		}
		cout<<endl;
	}
				cout<<"i，j最短路径矩阵为："<<endl;

				for(i=1;i<=6;i++)
	{
		for(j=1;j<=6;j++)
		{
			if(A[i][j]>=∞)
			{
				cout<<"∞ ";
			}
			else
			{
				cout<<A[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}