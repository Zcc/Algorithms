#include <iostream>
using namespace std;

int DKNAP(int p[],int w[],int n,int M)
{
	int pp,ww,F[100],l,h,u,i,j,next,P[100],W[40],k,x[10];
	F[0]=1;
	P[1]=0;
	W[1]=0;
	l=h=1;
	F[1]=next=2;
	for(i=1;i<=n;i++)
	{
		k=1;
		for(j=l;j<=h;j++)
		{
			if((W[j]+w[i])<=M)
			{
				u=j;
			}
		}
		for(j=1;j<=u;j++)
		{
			pp=P[j]+p[i];
			ww=W[j]+w[i];
			while(k<=h&&W[k]<ww)
			{
				P[next]=P[k];
				W[next]=W[k];
				next++;
				k++;
			}
			if(k<=h&&W[k]==ww)
			{
				if(pp<P[k]){
					pp=P[k];}
				k++;
			}
			if(pp>P[next-1])
			{
				P[next]=pp;
				W[next]=ww;
				next++;
			}
			while(k<=h&&P[k]<=P[next-1])
			{
				k++;
			}
		}
		while(k<=h)
		{
			P[next]=P[k];
			W[next]=W[k];
			next++;
			k++;
		}
		l=h+1;
		h=next-1;
		F[i+1]=next;
	}
//	PARTS;
	pp=P[next-1];
	ww=W[next-1];
	for(i=n;i>=1;i--)
	{
		x[i]=1;
		for(j=F[i]-1;j>=F[i-1];j--)
		{
			if((P[j]==pp)&&(W[j]==ww))
			{
				x[i]=0;
			}
		}
		pp=pp-p[i];
		ww=ww-w[i];
	}
	for(i=1;i<=n;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
	return 0;
}

int main()
{
	int p[4]={0,1,2,5},i;
	int w[4]={0,2,3,4};
	cout<<"****************0//1������̬�滮��ʾ***********"<<endl<<"������������Ϊ��n=3,M=6"<<endl<<"����Ϊ��"<<endl;
	for(i=1;i<4;i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl<<"Ч��Ϊ��"<<endl;
		for(i=1;i<4;i++)
	{
		cout<<w[i]<<" ";
	}
		cout<<endl<<"��̬�滮������Ž�Ϊ��"<<endl;
	DKNAP(p,w,3,6);
	return 0;
}