#include <iostream>
using namespace std;

//��arr�д�firstlocation��lastlocationλ�ü�����num
int BinSearch(const int arr[],int firstlocation,int lastlocation,const int num)
{
	int mid = (firstlocation+lastlocation)/2;
	if(firstlocation>lastlocation)
	{
		return -1;
	}
	if(num==arr[mid-1])
	{
		return mid;
	}
	if(num<arr[mid-1])
	{
		return BinSearch(arr,firstlocation,mid-1,num);
	}
	if(num>arr[mid-1])
	{
		return BinSearch(arr,mid+1,lastlocation,num);
	}
	
}

int main()
{
	int arr[10]={2,4,6,8,10,100,200,300,400,500},num,tmp;
	cout<<"���зǵݼ�������������飬������һ�������жϴ����Ƿ��ڴ������ڣ�"<<endl;
	cin>>num;
	tmp = BinSearch(arr,1,10,num);
	if(tmp==-1)
	{
		cout<<"�������������С�"<<endl;
	}
	else
	{
		cout<<"����������ĵ�"<<tmp<<"��λ��"<<endl;
	}
	
	return 0;
}