#include<iostream>
using namespace std;


void SumOfSub(int s,int k,int r,int M,int n,int W[],int X[])
{
	int j;
	X[k]=1;
	if(s+W[k]==M)
	{
		for(j=1;j<=k;j++)
		{
			cout<<X[j]<<" "; 
		}
		cout<<endl;
	}
	else
	{
		if((s+W[k]+W[k+1])<=M)
		{
			SumOfSub(s+W[k],k+1,r-W[k],M,n,W,X);
		}
	}
	if((s+r-W[k])>=M&&(s+W[k+1])<=M)
	{
		X[k]=0;
		SumOfSub(s,k+1,r-W[k],M,n,W,X);
	}
}

int main()
{
	cout<<"*******�Ӽ���������********"<<endl<<"���룺"<<endl<<"Mֵ:30"<<endl<<"Ȩ����Ϊ��"<<endl;
	int W[7]={0,5,10,12,13,15,18};
	int X[7]={0,0,0,0,0,0,0};
	for(int i=1;i<7;i++)
	{
		cout<<W[i]<<" ";
	}
	cout<<endl<<"���ݷ�ȷ���Ľ⼯Ϊ��"<<endl;
	SumOfSub(0,1,73,30,6,W,X);
	return 0;
}