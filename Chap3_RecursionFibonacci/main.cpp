#include <iostream>
using namespace std;

int Fibonacci(int num)
{
	if(num==0||num==1)
	{
		return num;
	}
	else
	{
		return Fibonacci(num-1)+Fibonacci(num-2);
	}

}

int main()
{
	int num,i;
	cout<<"������Ҫ��ӡ��쳲��������еĸ�����";
	cin>>num;
	for(i=0;i<num;i++)
	{
	cout<<Fibonacci(i)<<" ";
	}
	cout<<endl;
	return 0;
}

