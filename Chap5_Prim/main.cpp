#include<iostream>
using namespace std;
#define ∞ 500
int FindNear(const int Cost[7][7],int near[],int n)
{
	int min = Cost[1][near[1]],k=1;
	for(int i=2;i<=n;i++)
	{
		if(near[i]!=0&&Cost[i][near[i]]<min)
		{	
			min = Cost[i][near[i]];
			k=i;
		}
	}

	return k;
}

int Find(const int Cost[7][7],int n,int *k,int *l)
{
	int i,j;
	int min= Cost[1][1];
		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				if(Cost[i][j]<min)
				{
					min=Cost[i][j];
					*k=i;
					*l=j;
				}
			}
		}
		return min;
}

int Prim(const int Cost[7][7],int n,int T[6][3])
{
	int k=0,l=0,i,j;
	int Near[7];
	int mincost = Find(Cost,7,&k,&l);
	T[1][1] = k;
	T[1][2] = l;
	for(i=1;i<=n;i++)
	{
		if(Cost[i][l]<Cost[i][k])
		{
			Near[i]=l;
		}
		else
		{
			Near[i]=k;
		}
	}
	Near[k]=0;
	Near[l]=0;
	for(i=2;i<n;i++)
	{
		j = FindNear(Cost,Near,n);
		T[i][1]=j;
		T[i][2]=Near[j];
		mincost=mincost+Cost[j][Near[j]];
		Near[j]=0;
		for(k=1;k<=n;k++)
		{
			if(Near[k]!=0&&Cost[k][Near[k]]>Cost[k][j])
			{
				Near[k]=j;
			}
		}
	}
	if(mincost>=∞)
	{
		cout<<"no spanning tree"<<endl;
	}
	return mincost;
}


int main()
{
	const int COST[7][7]={{∞,∞,∞,∞,∞,∞,∞},{∞,∞,10,∞,30,45,∞},{∞,10,∞,50,∞,40,25},{∞,∞,50,∞,∞,35,15},{∞,30,∞,∞,∞,∞,20},{∞,45,40,35,∞,∞,55},{∞,∞,25,15,20,55,∞}};
//	int k=0,l=0;
//	cout<<Find(COST,7,&k,&l);
//	cout<<k<<l;
	cout<<"原图的临接矩阵为："<<endl;
	int T[6][3],j,i;
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

	
		cout<<"prime最小生成数成本和为："<<Prim(COST,6,T)<<endl<<"prime最小生产树的各条边为："<<endl;
	for( i=1;i<=5;i++)
	{
			cout<<T[i][1]<<"-"<<T[i][2]<<endl;
	}
	return 0;
}