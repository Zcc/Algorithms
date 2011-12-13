#include <iostream>
using namespace std;

void OBST(int P[],int Q[],int n)
{
	int C[20][20],W[20][20],i,m,j,k,min,a,R[20][20],mmin[20];
	for(int i=0;i<n;i++)
	{
		W[i][i]=Q[i];
		R[i][i]=0;
		C[i][i]=0;
		W[i][i+1]=Q[i]+Q[i+1]+P[i+1];
		R[i][i+1]=i+1;
		C[i][i+1]=Q[i]+Q[i+1]+P[i+1];
	}
	W[n][n]=Q[n];
	R[n][n]=0;
	C[n][n]=0;
	for(m=2;m<=n;m++)
	{
		for(i=0;i<=n-m;i++)
		{
			j=i+m;
			W[i][j]=W[i][j-1]+P[j]+Q[j];
			min = C[i][R[i][j-1]-1]+C[R[i][j-1]][j];
			a=R[i][j-1];
			for(k=R[i][j-1]+1;k<=R[i+1][j];k++)
			{
				if((C[i][k-1]+C[k][j])<min)
				{
					min = C[i][k-1]+C[k][j];
					a=k;
				}
			}
			C[i][j]=W[i][j]+C[i][a-1]+C[a][j];
			R[i][j]=a;
		}
	}
	cout<<R[0][n]<<" "<<R[0][R[0][n]-1]<<" "<<R[R[0][n]][n]<<" "<<R[R[R[0][n]][n]][n]<<endl;

}

int main()
{	
	int P[5]={0,3,3,1,1},i;
	int Q[5]={2,3,1,1,1};
	cout<<"P:";
	for(i=0;i<5;i++)
	{
		cout<<P[i]<<" ";
	}
		cout<<endl<<"Q:";
	for(i=0;i<5;i++)
	{
		cout<<Q[i]<<" ";
	}
	cout<<endl<<"由动态规划生成的最优二分检索数的宽度优先遍历次序为："<<endl;
	OBST(P,Q,4);
	return 0;
}