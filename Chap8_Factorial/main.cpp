#include <iostream>
using namespace std;


int Place(int k,int X[])
{
	int i;
	i=1;
	while(i<k)
	{
		if(X[i]==X[k])
		{
			return 0;
		}
		i++;
	}
	return 1;
}

void Factorial(int n)
{
	int k,X[50],i;
	X[1]=0;
	k=1;
	while(k>0)
	{
		X[k]++;
		while(X[k]<=n&&!Place(k,X))
		{
			X[k]++;
		}
		if(X[k]<=n)
		{
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
				k++;
				X[k]=0;
				
			}
		}
		else
		{
			k--;
		}
	}
}


int main()
{
	int n;
	cout<<"*******n�׳�ȫ�������*********"<<endl<<"������Ҫ��ӡȫ���е�nֵ��";
	cin>>n;
	Factorial(n);
	return 0;
}