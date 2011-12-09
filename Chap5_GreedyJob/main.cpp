#include<iostream>
using namespace std;

void JS(int D[],int J[],int n)
{
	int k,i,r,j;
	k=1;
	J[1]=1;
	for(i=2;i<=n;i++)
	{
		r=k;
		while(D[J[r]]>D[i]&&D[J[r]]!=r)
		{
			r--;
		}
		if(D[J[r]]<=D[i]&&D[i]>r)
		{
			for(j=k;j>=r+1;j--)
			{
				J[j+1]=J[j];
			}
			J[r+1]=i;
			k++;
		}
	}
}

void PrintArray(int arr[],int length)
{
	for(int i=1;i<length;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int P[7]={0,20,8,7,6,5,3};
	int D[7]={0,4,3,1,2,2,1};
	int J[7]={0,0,0,0,0,0,0};
	cout<<"效益值为:"<<endl;
		PrintArray(P,7);
	cout<<"相应的期限为："<<endl;
	PrintArray(D,7);
	JS(D,J,6);
		cout<<"贪心排序后的作业排序为："<<endl;

	PrintArray(J,7);
	return 0;
}


