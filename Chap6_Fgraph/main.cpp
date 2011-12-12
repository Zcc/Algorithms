#include <iostream>
using namespace std;

struct mulgraph
{
  int i,j,cost;
};

int Findmin(int j,mulgraph E[],int n,int Cost[])
{
	int min = 10000,r;
	for(int i=0;i<21;i++)
	{
		if(E[i].i==j)
		{
			if(E[i].cost+Cost[E[i].j]<min)
			{
				min = E[i].cost+Cost[E[i].j];
				r=E[i].j;
			}
		}
	}
	Cost[j]= min;

	return r;
}

int Fgraph(mulgraph E[],int n,int k,int P[])
{
	int Cost[20],D[20],r,j;
	Cost[n]=0;
	for(j=n-1;j>=1;j--)
	{
		r=Findmin(j,E,n,Cost);
		D[j]=r;
	}
	P[1]=1;P[k]=n;
	for(j=2;j<=k-1;j++)
	{
		P[j]=D[P[j-1]];
	}
	return 0;
}

int main()
{
	mulgraph E[21]={{1,2,9},{1,3,7},{1,4,3},{1,5,2},{2,6,4},{2,7,2},{2,8,1},{3,6,2},{3,7,7},{4,8,11},{5,8,8},{5,7,11},{6,9,6},{6,10,5},{7,9,4},{7,10,3},{8,10,5},{8,11,6},{9,12,4,},{10,12,2},{11,12,5}};
	int P[6]={0,0,0,0,0,0};
	Fgraph(E,12,5,P);
	cout<<"���ͼ��ǰ�����㷨��ʾ��"<<endl<<"����Ķ��ͼΪ����P125ҳ�Ķ��ͼ��"<<endl;
	cout<<"��"<<" "<<"��"<<" "<<"�ɱ�"<<endl;
	for(int i=0;i<21;i++)
	{
		cout<<E[i].i<<"   "<<E[i].j<<"   "<<E[i].cost<<endl;
	}
		cout<<"���ͼ��ǰ��������С�ɱ�·��Ϊ"<<endl;

	cout<<P[1]<<" "<<P[2]<<" "<<P[3]<<" "<<P[4]<<" "<<P[5]<<endl;
	return 0;
}