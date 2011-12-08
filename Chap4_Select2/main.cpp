//选择问题：确定数组中第k小的元素，并把它放在位置k上
#include<iostream>
using namespace std;

//对数组arr[p...r]就地重排
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


void Insertion_Sort(int arr[],int m,int l)
{
	int key,j;
	for(int i = m+1; i <= l; i++)
	{
		key = arr[i];
		j=i-1;
		while(j>=m&&arr[j]>key)
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

int SEL(int arr[],int m,int p,int k)
{
	int r = 5,n,i,tmp,j;
	if((p-m+1)<=r)
	{
		Insertion_Sort(arr,m,p);
		return (m+k-1);
	}
	while(true)
	{
		n = p-m+1;
		for(i=1;i<=(n/r);i++)
		{
			Insertion_Sort(arr,m+(i-1)*r,m+i*r-1);
			tmp = arr[m+i-1];
			arr[m+i-1] = arr[m+(i-1)*r+r/2];
			arr[m+(i-1)*r+r/2] = tmp;
		}
		if(n<=r)
		{
				Insertion_Sort(arr,m,p);
				j=m+k-1;
		}
		else
		{
			j=SEL(arr,m,m+n/r-1,((n/r)+1)/2);
		}
		tmp = arr[m];
		arr[m] = arr[j];
		arr[j] = tmp;
		j = Partition(arr,m,p);
		if((j-m+1)==k)
		{
			return j;
		}
		else if((j-m+1)>k)
		{
			p=j-1;
		}
		else
		{
			k=k-(j-m+1);
			m=j+1;
		}
	}
}

int main()
{
	int arr[16] = {4,5,765,44,34,56,73,22,64,37,88,65,36,78,54,53},num;
	cout<<"原数组为："<<endl;
	PrintArray(arr,16);
	cout<<"请输入需要确定的第k小的数："<<endl;
	cin>>num;
	cout<<"第k小的数为："<<endl;
	cout<<arr[SEL(arr,0,15,num)]<<endl;
	cout<<"确定好的数组为："<<endl;
	PrintArray(arr,16);
	return 0;
}