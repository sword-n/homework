#include<iostream>
#define OK 1
#define ERROR 0
#include <stdlib.h>
#include <time.h>
using namespace std;
#include <iomanip>
using std::setw;

struct PCB//进程控制块的结构定义 
{
	char name;//用数字对数据块标号 1-10 
	int state;//其状态为0或1 其中0表示 等待状态 1表示就绪状态 
	int prior;//优先级  随机数1-10 
	int time; //执行进程所需时间 随机产生  
};
//////////////////////////////////////////////////队列的链式存储结构 
typedef struct QNode//定义结点
{
   PCB   data;
   struct QNode  *next;
} QNode, *QueuePtr;
typedef struct 
{
   QueuePtr  front;            //队头指针   
   QueuePtr  rear;             //队尾指针
}LinkQueue; 
/////////////////////////////////////////////////以下是处理链队的基本函数
 int InitQueue (LinkQueue &Q)//初始化队列
{
   Q.front=Q.rear=new QNode;
    Q.front->next=NULL;
    return OK;
}
int EnQueue(LinkQueue &Q,PCB e)//将一个结点插入到队列当中 
{ 
	QueuePtr p=new QNode;
    if(!p) 
		exit(0);
    p->data=e;
	p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}
int PrintQueue(LinkQueue &Q)//打印整个队列
{
	QueuePtr p=new QNode;
	if(Q.front==Q.rear) 
		return ERROR;
	p=Q.front->next;
	do
	{
		cout<<setw(20)<<p->data.name<<setw(10)<<p->data.state<<setw(10)<<p->data.prior<<setw(10)<<p->data.time<<endl;
		p=p->next;
	}while(p!=NULL);
	cout<<endl;
	delete p;
	return OK;
}
int DeQueue (LinkQueue &Q,PCB &e)//删除一个结点 
{
	QueuePtr p=new QNode;
   if(Q.front==Q.rear) return ERROR;
   p=Q.front->next;
   e=p->data;
   Q.front->next=p->next;
   if(Q.rear==p) Q.rear=Q.front;
   delete p;
   return OK;
}
int GetHead (LinkQueue &Q,PCB &e)//读取对列头元素
{
	e=Q.front->next->data;
	return OK;
}
int QueueEmpty (LinkQueue Q)//判断队列是否为空，为空则返回0
{
	
	if(Q.front==Q.rear)
		return 0;    
	else
		return 1;
 }
 void fifo(LinkQueue &wait,LinkQueue &ok,LinkQueue &run)//先进先出调度算法，wait为等待对列，ok为就绪队列,run为运行队列 
{
	srand((unsigned)time(NULL));//让随机数不重复
	PCB temp1; 
	int t;
	while(QueueEmpty(wait)==1||QueueEmpty(ok)==1)//当等待或者就绪队列其中一个不为空时执行 
	{
		int cpu=rand()%50+1; 
		///////////////////////////////////////////////就绪队列放一个元素到运行队列中
		if(1==QueueEmpty(ok))//ok队列非空
		{
			DeQueue (ok,temp1);//就绪队列中出一个元素
			if(temp1.time<=cpu) 
			{
				temp1.state=2;		//2表示运行状态 
				EnQueue(run,temp1);//就绪队列头进入运行队列
				cout<<endl<<endl<<endl;
				cout<<"当前执行进程为："<<temp1.name<<endl;
				cout<<"执行完成!!!!\n该进程所需时间为："<<temp1.time<<"\n随机产生的cpu时间为："<<cpu<<endl;
			}
			else
			{
				cout<<"当前执行进程为："<<temp1.name<<endl;
				cout<<"执行一部分，该进程所需时间为："<<temp1.time<<"\ncpu时间片不够且执行时间为："<<cpu<<endl;
				temp1.time=temp1.time-cpu;
				int j=rand()%2;
				if(j==1)
				{
					EnQueue(ok,temp1);
				}
				else
				{
					EnQueue(wait,temp1); 
				 } 
			}
		}
		else
		{
			cout<<"就绪队列为空"<<endl;
		}		
//////////////////////////////////////////////////////////产生一个随机数0或者1，1的话等待队列的第一个进程插入到就绪队列
		if(1==QueueEmpty(wait))//等待队列非空
		{
			int j=rand()%2;
			if(j==1)
			{
				DeQueue (wait,temp1);
				temp1.state = 1;
				EnQueue(ok,temp1);
			}
		}
	////////////////////////////////////////////////////////////输出运行情况
		cout<<setw(22)<<"进程名"<<setw(9)<<"状态"<<setw(11)<<"优先级"<<setw(11)<<"执行时间"<<endl;
		cout<<"就绪队列为："<<endl;//打印三个队列
		PrintQueue(ok);
		cout<<"等待队列为："<<endl;
		PrintQueue(wait);
	}//end while
}
void prior(LinkQueue &wait,LinkQueue &ok,LinkQueue &run)
{//基于优先数调度算法，wait为等待对列，ok为就绪队列，run为运行队列 
	srand((unsigned)time(NULL));//让随机数不重复
	QueuePtr p=new QNode;
	PCB temp;
	int t;
	while(QueueEmpty(wait)==1||QueueEmpty(ok)==1)///当等待或者就绪队列其中一个不为空时执行 
	{
		int cpu=rand()%50+1; 
		///////////////////////////////////////////////就绪队列放一个元素到运行队列中
		if(1==QueueEmpty(ok))//ok队列非空
		{	
			DeQueue (ok,temp);//先从就绪队列中取出队头 
			p=ok.front->next;
			while(p!=NULL)//就绪队列中出一个优先级最高，数字最小的元素
			{	
				if(temp.prior >  p->data.prior)//取出进程优先级数大于q所指时 
				{
					EnQueue(ok,temp);//又将取出的插到队尾 
					DeQueue(ok,temp);//再取出队头比较 
					p=ok.front->next;//q指向队列下一个元素 
				}
				else
				{
					p=p->next;
				}
			}
			temp.state=2;
			EnQueue(run,temp);//就绪队列头进入运行队列
			cout<<endl<<endl<<endl;
			if(temp.time<=cpu) 
			{
				temp.state=2;		//2表示运行状态 
				EnQueue(run,temp);//就绪队列头进入运行队列
				cout<<endl<<endl<<endl;
				cout<<"当前执行进程为："<<temp.name<<endl;
				cout<<"执行完成!!!!\n该进程所需时间为："<<temp.time<<"\n随机产生的cpu时间为："<<cpu<<endl;
			} 
			else
			{
				cout<<"当前执行进程为："<<temp.name<<endl;
				cout<<"执行一部分，该进程所需时间为："<<temp.time<<"\ncpu时间片不够且执行时间为："<<cpu<<endl;
				temp.time=temp.time-cpu;
				int j=rand()%2;
				if(j==1)
				{
					EnQueue(ok,temp);
				}
				else
				{
					EnQueue(wait,temp); 
				 } 
			}
		}
		else
		{
			cout<<"就绪队列为空"<<endl;
			
		}
//////////////////////////////////////////////////////////等待队列的第一个进程插入到就绪队列
		if(1==QueueEmpty(wait))//等待队列非空
		{
			int j=rand()%2;
			if(j==1)
			{
				DeQueue ( wait,temp);
				temp.state = 1;
				EnQueue(ok,temp);
			}
		}
	////////////////////////////////////////////////////////////输出运行情况
		cout<<setw(22)<<"进程名"<<setw(9)<<"状态"<<setw(11)<<"优先级"<<setw(11)<<"执行时间"<<endl;
		cout<<"就绪队列为："<<endl;//打印三个队列
		PrintQueue(ok);
		cout<<"等待队列为："<<endl;
		PrintQueue(wait);	
	}//end while
}
void shorttime(LinkQueue &wait,LinkQueue &ok,LinkQueue &run)
{//最短执行时间调度算法，wait为等待对列，ok为就绪队列，run为运行队列 
srand((unsigned)time(NULL));//让随机数不重复
	QueuePtr p=new QNode;
	PCB temp;
	int t;
	while(QueueEmpty(wait)==1||QueueEmpty(ok)==1)///当等待或者就绪队列其中一个不为空时执行 
	{
		int cpu=rand()%50+1; 
		///////////////////////////////////////////////就绪队列放一个元素到运行队列中
		if(1==QueueEmpty(ok))//ok队列非空
		{	
			DeQueue (ok,temp);//先从就绪队列中取出队头 
			p=ok.front->next;
			while(p!=NULL)//就绪队列中出一个优先级最高，数字最小的元素
			{	
				if(temp.time > p->data.time)//取出进程优先级数大于q所指时 
				{
					EnQueue(ok,temp);//又将取出的插到队尾 
					DeQueue(ok,temp);//再取出队头比较 
					p=ok.front->next;//q指向队列下一个元素 
				}
				else
				{
					p=p->next;
				}
			}
			temp.state=2;
			EnQueue(run,temp);//就绪队列头进入运行队列
			cout<<endl<<endl<<endl;
			if(temp.time<=cpu) 
			{
				temp.state=2;		//2表示运行状态 
				EnQueue(run,temp);//就绪队列头进入运行队列
				cout<<endl<<endl<<endl;
				cout<<"当前执行进程为："<<temp.name<<endl;
				cout<<"执行完成!!!!\n该进程所需时间为"<<temp.time<<"\n随机产生的cpu时间为"<<cpu<<endl;
			}
			else
			{
				cout<<"当前执行进程为："<<temp.name<<endl;
				cout<<"执行一部分，该进程所需时间为"<<temp.time<<"\ncpu时间片不够且执行时间为"<<cpu<<endl;
				temp.time=temp.time-cpu;
				int j=rand()%2;
				if(j==1)
				{
					EnQueue(ok,temp);
				}
				else
				{
					EnQueue(wait,temp); 
				 } 
			}
		}
		else
		{
			cout<<"就绪队列为空"<<endl;
			
		}
//////////////////////////////////////////////////////////等待队列的第一个进程插入到就绪队列
		if(1==QueueEmpty(wait))//等待队列非空
		{
			int j=rand()%2;
			if(j==1)
			{
				DeQueue ( wait,temp);
				temp.state = 1;
				EnQueue(ok,temp);
			}
		}
	////////////////////////////////////////////////////////////输出运行情况
		cout<<setw(22)<<"进程名"<<setw(9)<<"状态"<<setw(11)<<"优先级"<<setw(11)<<"执行时间"<<endl;
		cout<<"就绪队列为："<<endl;//打印三个队列
		PrintQueue(ok);
		cout<<"等待队列为："<<endl;
		PrintQueue(wait);
	}
}
 void print(PCB &s)//打印单个进程的情况
{
	cout<<setw(20)<<s.name<<setw(10)<<s.state<<setw(10)<<s.prior<<setw(10)<<s.time<<endl;
}
 int main()
{
	int i,j,m,b,k;
	char c;
    char n[11]="ABCDEFGHIJ";
	LinkQueue ok,wait,run;
	cout<<"十个随机进程为："<<endl; 
	cout<<setw(22)<<"进程名"<<setw(9)<<"状态"<<setw(11)<<"优先级"<<setw(11)<<"执行时间"<<endl;
	do
	{
		InitQueue (ok);//初始化等待队列和就绪队列
		InitQueue (wait);
		InitQueue (run);
		for(i=0;i<10;i++)//随机产生10个进程 包含名称 状态 优先级 执行所需时间 
		{
			PCB p;
			p.name=n[i];//名称为1-10 
			j=rand()%2;//产生随机数0和1,若为1。则就绪,若为0则等待
			p.state=j;
			m=rand()%10;//产生随机数0-9 
			p.prior=m+1;//随机数1-10表示优先级 
			p.time=rand()%50+1;
			if(j==1)
				EnQueue(ok,p);
			else	
				EnQueue(wait,p);
			print(p);//打印单个进程 
		}
		cout<<"就绪队列为："<<endl;
		PrintQueue(ok);
		cout<<"等待队列为： "<<endl;
		PrintQueue(wait);
		cout<<endl<<endl;
		cout<<"就绪和等待队列已经生成,请选择您希望的调度算法:     "<<endl;
		cout<<"   1.先入先出调度算法                              "<<endl;
		cout<<"   2.基于优先数的调度算法                          "<<endl;
		cout<<"   3.最短执行时间调度算法                          "<<endl;
		cout<<"   请输入数字1-3选择功能:";
		cin>>b;
		switch(b)
		{
			case 1:fifo(wait,ok,run);break;
			case 2:prior(wait,ok,run);break;
			case 3:shorttime(wait,ok,run);break;
			default:cout<<"输入有误"<<endl;
		}
		cout<<endl<<endl<<"继续执行输入y,退出系统输入n："<<endl;
		cin>>c;
	}while(c=='Y'||c=='y');///////////////////////////////////////////end do
	system("cls");//分页 
	return 0;
}

