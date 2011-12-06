#include <iostream>
using namespace std;

void Insertion_Sort(int arr[],int length)
{
	int key,j;
	for(int i = 1; i < length; i++)
	{
		key = arr[i];
		j=i-1;
		while(j>=0&&arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void PrintArray(int arr[],int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int arr[5];
	cout<<"*********插入排序算法演示*********"<<endl;
	cout<<"请输入5个整数："<<endl;
	cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4];
	Insertion_Sort(arr,5);
	PrintArray(arr,5);
	return 0;
}

