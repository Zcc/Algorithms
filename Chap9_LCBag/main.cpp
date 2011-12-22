#include<iostream>
using namespace std;

class bbnode
{//结点类
	friend class Knap;
	friend float Knapsack(float *, int *, int, int, int *);
private:
	bbnode * parent;//指向父结点指针
	bool LChild;//左儿子结点标志
};

class Object
{//物品类
	friend float Knapsack(float *, int *, int, int, int *);
	friend void Sort(Object & Q, int n);
public:
	int operator <=(Object a)const{return(d<=a.d);}
	int ID;
	float d;//单位重量价值
};

class HeapNode
{
	friend class Knap;
	friend class MaxHeap;
public:
	operator float () const {return uprofit;}
private:
	float uprofit, profit;
	int weight;
	int level;
	bbnode *ptr;
};

class MaxHeap{//注：为了简单起见大顶堆采用了简单实现，即用数组加以代替
public:
	MaxHeap(){
		head=new HeapNode[100];
		size=100; height=0; length=0; }
	void Insert(HeapNode N)
	{
		if(length>=size){cout<<"堆空间不够"<<endl;exit(1);
		}
		head[length].uprofit=N.uprofit, head[length].profit=N.profit,
			head[length].weight=N.weight; head[length].level=N.level,
			head[length].ptr=N.ptr;
		length++; 
	}
	HeapNode DeleteMax()
	{
		HeapNode temp;
		temp.weight=0;
		int local=0;
		for(int i=0; i<length; i++)
			if(head[i].weight>temp.weight)
			{
				temp.weight=head[i].weight;
				local=i;   
			}
			temp.level=head[local].level, temp.profit=head[local].profit,
				temp.ptr=head[local].ptr, temp.uprofit=head[local].uprofit,
				temp.weight=head[local].weight;
			for(int j=local; j<length; j++)
			{
				head[j]=head[j+1];
			}
			length--;
			return temp;
	}
private:
	HeapNode * head;
	int height;
	int length;
	int size;
};

class Knap{ friend float Knapsack(float *, int *, int, int, int*);
public:
	float MaxKnapsack(){
		H=new MaxHeap();
		bestx=new int[n+1];
		int i=1;
		E=0;
		cw=cp=0;
		float bestp=0;
		float up=Bound(1);
		while(i!=n+1){
			int wt = cw+w[i];
			if(wt<=c){
				if(cp+p[i]>bestp)bestp=cp+p[i];
				AddLiveNode(up,cp+p[i],cw+w[i],true,i+1);
			}
			up=Bound(i+1);
			if(up>=bestp)AddLiveNode(up,cp,cw,false,i+1);
			HeapNode N;
			N=H->DeleteMax();
			E=N.ptr;
			cw=N.weight;
			cp=N.profit;
			up=N.uprofit;
			i=N.level;
		}
		for(int j=n; j>0; j--){
			bestx[j]=E->LChild;
			E=E->parent;
		}
		return cp;
	}
private:
	MaxHeap * H;
      float Bound(int i){

            int cleft = c-cw;

            float b = cp;

            while(i<=n && w[i]<=cleft){

                  cleft-=w[i];

                  b+=p[i];

                  i++;

            }

            if(i<=n)b+=p[i]/w[i]*cleft;

            return b;

      }
	void AddLiveNode(float up, float cp, int cw, bool ch, int level){
		bbnode * b=new bbnode;
		b->parent=E;
		b->LChild=ch;
		HeapNode N;
		N.uprofit=up;
		N.profit=cp;
		N.weight=cw;
		N.level=level;
		N.ptr=b;
		H->Insert(N);
	}
	bbnode * E;
	int c;
	int n;
	int * w;
	float * p;
	int cw;
	float cp;
	int * bestx;
};
void Sort(Object * Q, int n){
	for(int i=0; i<n; i++)
		for(int j=0; j<n-i-1; j++){
			if(Q[j]<=Q[j+1]){
				Object temp;
				temp.d=Q[j].d; temp.ID=Q[j].ID;
				Q[j].d=Q[j+1].d; Q[j].ID=Q[j+1].ID;
				Q[j+1].d=temp.d; Q[j+1].ID=temp.ID;
			}
		}
}
float Knapsack(float p[], int w[], int c, int n, int bestx[]){
	int W=0;
	float P=0.0;
	Object * Q=new Object[n];
	for(int t=0; t<n; t++){
		Q[t].ID=t+1;
		Q[t].d=1.0*p[t]/w[t];
		P+=p[t];
		W+=w[t]; }
	if(W<=c) return P;
	Sort(Q,n);
	Knap K;
	K.p=new float[n+1];
	K.w=new int[n+1];
	for(int i=1; i<=n; i++){
		K.w[i]=w[Q[i-1].ID-1];//0号单元未用
		K.p[i]=p[Q[i-1].ID-1];//0号单元未用
	}
	K.cp=0;
	K.cw=0;
	K.c=c;
	K.n=n;
	float bestp=K.MaxKnapsack();
	for(int j=1; j<=n; j++)
	{
		bestx[Q[j-1].ID]=K.bestx[j]; 
	}
	delete[] Q;
	delete[] K.w;
	delete[] K.p;
	delete[] K.bestx;
	return bestp;
}
void main(){ 
	int n=4;
	cout<<"****LC0/1背包问题演示*********"<<endl<<"输入为书中例子"<<endl<<"物品数量n："<<n<<endl;
	int c=15;
	cout<<"背包容量M："<<c<<endl;
	int w[]={2,4,6,9};
	cout<<"物品重量w：";
	for(int t=0; t<n; t++)cout<<w[t]<<" ";cout<<endl;
	float p[]={10,10,12,18};
	cout<<"物品价值p：";
	for(int s=0; s<n; s++)cout<<p[s]<<" ";cout<<endl;
	int bestx[]={0,0,0,0,0,0,0};
	float bestp=Knapsack(p,w,c,n,bestx);
	cout<<"最优值为："<<bestp<<endl;
	cout<<"最优解为：";
	for(int i=1; i<=n; i++)
		cout<<"X"<<i<<"="<<bestx[i]<<"  ";
	cout<<endl;
}