#include <iostream>
using namespace std;

//������arr[p...r]�͵�����
int Partition(int arr[],int m,int p)
{
	int i,tmp;
	i = m+1;
	while(true)
	{
		while(arr[i]<=arr[m])
		{
			i++;
		}
		while(arr[p]>=arr[m]&&p>0)
		{
			p--;
		}
		if(i<p)
		{
			tmp = arr[i];
			arr[i] = arr[p];
			arr[p] = tmp;
		}
		else
		{
			break;
		}
		i++;
		p--;
	}
	tmp = arr[m];
	arr[m]=arr[p];
	arr[p]= tmp;
	return p;
}

void PrintArray(int arr[],int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void QuickSort(int arr[],int p,int q)
{
	int par;
	if(p<q)
	{
		par = Partition(arr,p,q);
		QuickSort(arr,p,par-1);
		QuickSort(arr,par+1,q);
	}
}

int main()
{
	int arr[10]={5,4,3,6,77,443,23,45,66,77};
	cout<<"ԭ����Ϊ��"<<endl;
	PrintArray(arr,10);
	QuickSort(arr,0,9);
	cout<<"��������������Ϊ��"<<endl;
	PrintArray(arr,10);
	return 0;
}