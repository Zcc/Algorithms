#include<iostream>
using namespace std;
typedef struct node
{
	int time;     //��¼��ѡ��ҵ����ʱ��
	int parent;         //��¼�ڵ�ĸ��׽ڵ�
	int x;     //��¼��ѡ����ҵ���
	float u,c;   //u,c�ֱ��¼�������޺͹��Ʒ���
	int date;  //��¼��ѡ��ҵ������ֹ����
}F;F q[30];   //���нṹ������
float p[10]={5,10,6,3};
int t[10]={1,2,1,1},d[10]={1,3,2,1},a[10]={0,1,2,3,4,5,6,7,8,9};
int i,j,D=4,k,E,b;
float co,up,max=1000,U,e=0.5;
F w[1];


int time(int k,int E)//�жϵ�ǰ��ѡ��ҵʱ���Ƿ��ͻ
{
	if(q[E].date <d[a[k]])
		w[0].date =d[a[k]];
	else w[0].date =q[E].date;
	if(q[E].time+t[a[k]]>w[0].date )
		return 0;
	else return 1;
}

void cost(int k,int E)//������Ƴɱ�����
{
	int m;
	if(!time(k,E))
		co=1000;
	else if(q[E].x-a[k]!=-1)
	{co=q[E].c;
	for(m=q[E].x+1;m<a[k];m++)
		co=co +p[m];
	}else co=q[E].c ;
	up=q[E].u -p[a[k]];
}

void enterq(int k,int E)//�����еĺ���
{
	q[j].c=co;q[j].date =d[a[k]];
	q[j].parent =E;q[j].time =q[E].time +t[a[k]];
	q[j].u =up;q[j].x =a[k];
	if(q[j].u <U)
	{ U=q[j].u +e;b=j;}//��¼�𰸽ڵ�
	j++;
}

int ynset()//�ж϶����Ƿ�Ϊ��
{
	if(i!=j)return 0;
	else return 1;
}

int outq()
{
	int t;
	t=i++;
	return t;
}


void FIFOBB(int E)//��֦�޽纯��
{
	int t;
	while(!ynset()||i==1)
	{ 
		for(k=q[E].x+1;k<D;k++)
		{
			cost(k,E);
			if(co<U)//�жϹ��Ƴɱ��Ƿ�С�ڷ������ޣ������������У����������
				enterq(k,E);
		}
		E=outq();
	}
	{   printf("��С���%f",U-e);
	printf("\n");
	printf("���Ž�Ϊ��%d",q[b].x+1);
	printf(" ");
	t=q[b].parent;
	while(q[t].parent !=-1)
	{
		printf("   %d",q[t].x+1 );
		printf("\n");
		t=q[t].parent;
	}
	}

}

void main()//������
{
	int i;
	cout<<"*********LC��������ҵ����***********"<<endl<<"���";
	for(i = 0; i < D; i++)
	{cout<<p[i]<<" ";}
	cout<<endl<<"���ޣ�";
	for(i = 0; i < D; i++)
		cout<<d[i]<<" ";
	cout<<endl<<"ʱ�䣺";
	for(i = 0; i < D; i++)
		cout<<t[i]<<" ";
	cout<<endl;
	q[0].c =0;//��ʼ�����ĸ��ڵ�
	q[0].u =24;
	q[0].date =0;
	q[0].time =0;
	q[0].parent =-1;
	q[0].x =-1;i=j=1;
	U=q[0].u +e;
	FIFOBB(0);

}
