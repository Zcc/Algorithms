#include <iostream>
using namespace std;

//在arr中从firstlocation到lastlocation位置检索数num
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
	cout<<"现有非递减序列排序的数组，请输入一个数，判断此数是否在此数组内："<<endl;
	cin>>num;
	tmp = BinSearch(arr,1,10,num);
	if(tmp==-1)
	{
		cout<<"此数不在数组中。"<<endl;
	}
	else
	{
		cout<<"此数在数组的第"<<tmp<<"个位置"<<endl;
	}
	
	return 0;
}