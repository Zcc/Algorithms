#include <iostream>
using namespace std;

int GCD(int num1,int num2)
{
	if(num2==0)
	{
		return num1;
	}
	else
	{
		return GCD(num2,num1%num2);
	}
}

int main()
{
	int num1,num2;
	cout<<"������������������"<<endl;
	cin>>num1>>num2;
	cout<<num1<<"��"<<num2<<"���������Ϊ��"<<GCD(num1,num2)<<endl;
	return 0;
}