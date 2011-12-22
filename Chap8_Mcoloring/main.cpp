#include <iostream>
using namespace std;

int NextValue(int k,int m,int n,int X[],int Graph[6][6])
{
	int j;
	while(true)
	{
		X[k]=(X[k]+1)%(m+1);
		if(X[k]==0)
		{
			return 0; 
		}
		for(j=1;j<=n;j++)
		{
			if(Graph[k][j]&&X[k]==X[j])
			{
				break;
			}
		}
		if(j==n+1)
		{
			return 0;
		}
	}
}

void  Mcoloring(int k,int m,int n,int X[],int Graph[6][6])
{
	int i;
	while(true)
	{
		NextValue(k,m,n,X,Graph);
		if(X[k]==0)
			return;
		if(k==n)
		{
			for(i=1;i<=n;i++)
			{
				cout<<X[i]<<" ";
			}
			cout<<endl;
			
		}
		else
		{
			Mcoloring(k+1,m,n,X,Graph);
		}
	}
}


int main()
{
	int Graph[6][6]={{0,0,0,0,0,0},{0,0,1,1,1,0},{0,1,0,1,1,1},{0,1,1,0,1,0},{0,1,1,1,0,1},{0,0,1,0,1,0}};
	int X[6]={0,0,0,0,0,0},i,j;
		cout<<"原图的临接矩阵为："<<endl;
		for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{

				cout<<Graph[i][j]<<" ";
			
		}
		cout<<endl;
	}
	cout<<"请输入颜色数："<<endl;
	cin>>i;
		cout<<"着色方案为："<<endl;
	Mcoloring(1,i,5,X,Graph);

	return 0;
}