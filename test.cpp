#include<iostream>
#define OK 1
#define ERROR 0
#include <stdlib.h>
#include <time.h>
using namespace std;
#include <iomanip>
using std::setw;

struct PCB//���̿��ƿ�Ľṹ���� 
{
	char name;//�����ֶ����ݿ��� 1-10 
	int state;//��״̬Ϊ0��1 ����0��ʾ �ȴ�״̬ 1��ʾ����״̬ 
	int prior;//���ȼ�  �����1-10 
	int time; //ִ�н�������ʱ�� �������  
};
//////////////////////////////////////////////////���е���ʽ�洢�ṹ 
typedef struct QNode//������
{
   PCB   data;
   struct QNode  *next;
} QNode, *QueuePtr;
typedef struct 
{
   QueuePtr  front;            //��ͷָ��   
   QueuePtr  rear;             //��βָ��
}LinkQueue; 
/////////////////////////////////////////////////�����Ǵ������ӵĻ�������
 int InitQueue (LinkQueue &Q)//��ʼ������
{
   Q.front=Q.rear=new QNode;
    Q.front->next=NULL;
    return OK;
}
int EnQueue(LinkQueue &Q,PCB e)//��һ�������뵽���е��� 
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
int PrintQueue(LinkQueue &Q)//��ӡ��������
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
int DeQueue (LinkQueue &Q,PCB &e)//ɾ��һ����� 
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
int GetHead (LinkQueue &Q,PCB &e)//��ȡ����ͷԪ��
{
	e=Q.front->next->data;
	return OK;
}
int QueueEmpty (LinkQueue Q)//�ж϶����Ƿ�Ϊ�գ�Ϊ���򷵻�0
{
	
	if(Q.front==Q.rear)
		return 0;    
	else
		return 1;
 }
 void fifo(LinkQueue &wait,LinkQueue &ok,LinkQueue &run)//�Ƚ��ȳ������㷨��waitΪ�ȴ����У�okΪ��������,runΪ���ж��� 
{
	srand((unsigned)time(NULL));//����������ظ�
	PCB temp1; 
	int t;
	while(QueueEmpty(wait)==1||QueueEmpty(ok)==1)//���ȴ����߾�����������һ����Ϊ��ʱִ�� 
	{
		int cpu=rand()%50+1; 
		///////////////////////////////////////////////�������з�һ��Ԫ�ص����ж�����
		if(1==QueueEmpty(ok))//ok���зǿ�
		{
			DeQueue (ok,temp1);//���������г�һ��Ԫ��
			if(temp1.time<=cpu) 
			{
				temp1.state=2;		//2��ʾ����״̬ 
				EnQueue(run,temp1);//��������ͷ�������ж���
				cout<<endl<<endl<<endl;
				cout<<"��ǰִ�н���Ϊ��"<<temp1.name<<endl;
				cout<<"ִ�����!!!!\n�ý�������ʱ��Ϊ��"<<temp1.time<<"\n���������cpuʱ��Ϊ��"<<cpu<<endl;
			}
			else
			{
				cout<<"��ǰִ�н���Ϊ��"<<temp1.name<<endl;
				cout<<"ִ��һ���֣��ý�������ʱ��Ϊ��"<<temp1.time<<"\ncpuʱ��Ƭ������ִ��ʱ��Ϊ��"<<cpu<<endl;
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
			cout<<"��������Ϊ��"<<endl;
		}		
//////////////////////////////////////////////////////////����һ�������0����1��1�Ļ��ȴ����еĵ�һ�����̲��뵽��������
		if(1==QueueEmpty(wait))//�ȴ����зǿ�
		{
			int j=rand()%2;
			if(j==1)
			{
				DeQueue (wait,temp1);
				temp1.state = 1;
				EnQueue(ok,temp1);
			}
		}
	////////////////////////////////////////////////////////////����������
		cout<<setw(22)<<"������"<<setw(9)<<"״̬"<<setw(11)<<"���ȼ�"<<setw(11)<<"ִ��ʱ��"<<endl;
		cout<<"��������Ϊ��"<<endl;//��ӡ��������
		PrintQueue(ok);
		cout<<"�ȴ�����Ϊ��"<<endl;
		PrintQueue(wait);
	}//end while
}
void prior(LinkQueue &wait,LinkQueue &ok,LinkQueue &run)
{//���������������㷨��waitΪ�ȴ����У�okΪ�������У�runΪ���ж��� 
	srand((unsigned)time(NULL));//����������ظ�
	QueuePtr p=new QNode;
	PCB temp;
	int t;
	while(QueueEmpty(wait)==1||QueueEmpty(ok)==1)///���ȴ����߾�����������һ����Ϊ��ʱִ�� 
	{
		int cpu=rand()%50+1; 
		///////////////////////////////////////////////�������з�һ��Ԫ�ص����ж�����
		if(1==QueueEmpty(ok))//ok���зǿ�
		{	
			DeQueue (ok,temp);//�ȴӾ���������ȡ����ͷ 
			p=ok.front->next;
			while(p!=NULL)//���������г�һ�����ȼ���ߣ�������С��Ԫ��
			{	
				if(temp.prior >  p->data.prior)//ȡ���������ȼ�������q��ָʱ 
				{
					EnQueue(ok,temp);//�ֽ�ȡ���Ĳ嵽��β 
					DeQueue(ok,temp);//��ȡ����ͷ�Ƚ� 
					p=ok.front->next;//qָ�������һ��Ԫ�� 
				}
				else
				{
					p=p->next;
				}
			}
			temp.state=2;
			EnQueue(run,temp);//��������ͷ�������ж���
			cout<<endl<<endl<<endl;
			if(temp.time<=cpu) 
			{
				temp.state=2;		//2��ʾ����״̬ 
				EnQueue(run,temp);//��������ͷ�������ж���
				cout<<endl<<endl<<endl;
				cout<<"��ǰִ�н���Ϊ��"<<temp.name<<endl;
				cout<<"ִ�����!!!!\n�ý�������ʱ��Ϊ��"<<temp.time<<"\n���������cpuʱ��Ϊ��"<<cpu<<endl;
			} 
			else
			{
				cout<<"��ǰִ�н���Ϊ��"<<temp.name<<endl;
				cout<<"ִ��һ���֣��ý�������ʱ��Ϊ��"<<temp.time<<"\ncpuʱ��Ƭ������ִ��ʱ��Ϊ��"<<cpu<<endl;
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
			cout<<"��������Ϊ��"<<endl;
			
		}
//////////////////////////////////////////////////////////�ȴ����еĵ�һ�����̲��뵽��������
		if(1==QueueEmpty(wait))//�ȴ����зǿ�
		{
			int j=rand()%2;
			if(j==1)
			{
				DeQueue ( wait,temp);
				temp.state = 1;
				EnQueue(ok,temp);
			}
		}
	////////////////////////////////////////////////////////////����������
		cout<<setw(22)<<"������"<<setw(9)<<"״̬"<<setw(11)<<"���ȼ�"<<setw(11)<<"ִ��ʱ��"<<endl;
		cout<<"��������Ϊ��"<<endl;//��ӡ��������
		PrintQueue(ok);
		cout<<"�ȴ�����Ϊ��"<<endl;
		PrintQueue(wait);	
	}//end while
}
void shorttime(LinkQueue &wait,LinkQueue &ok,LinkQueue &run)
{//���ִ��ʱ������㷨��waitΪ�ȴ����У�okΪ�������У�runΪ���ж��� 
srand((unsigned)time(NULL));//����������ظ�
	QueuePtr p=new QNode;
	PCB temp;
	int t;
	while(QueueEmpty(wait)==1||QueueEmpty(ok)==1)///���ȴ����߾�����������һ����Ϊ��ʱִ�� 
	{
		int cpu=rand()%50+1; 
		///////////////////////////////////////////////�������з�һ��Ԫ�ص����ж�����
		if(1==QueueEmpty(ok))//ok���зǿ�
		{	
			DeQueue (ok,temp);//�ȴӾ���������ȡ����ͷ 
			p=ok.front->next;
			while(p!=NULL)//���������г�һ�����ȼ���ߣ�������С��Ԫ��
			{	
				if(temp.time > p->data.time)//ȡ���������ȼ�������q��ָʱ 
				{
					EnQueue(ok,temp);//�ֽ�ȡ���Ĳ嵽��β 
					DeQueue(ok,temp);//��ȡ����ͷ�Ƚ� 
					p=ok.front->next;//qָ�������һ��Ԫ�� 
				}
				else
				{
					p=p->next;
				}
			}
			temp.state=2;
			EnQueue(run,temp);//��������ͷ�������ж���
			cout<<endl<<endl<<endl;
			if(temp.time<=cpu) 
			{
				temp.state=2;		//2��ʾ����״̬ 
				EnQueue(run,temp);//��������ͷ�������ж���
				cout<<endl<<endl<<endl;
				cout<<"��ǰִ�н���Ϊ��"<<temp.name<<endl;
				cout<<"ִ�����!!!!\n�ý�������ʱ��Ϊ"<<temp.time<<"\n���������cpuʱ��Ϊ"<<cpu<<endl;
			}
			else
			{
				cout<<"��ǰִ�н���Ϊ��"<<temp.name<<endl;
				cout<<"ִ��һ���֣��ý�������ʱ��Ϊ"<<temp.time<<"\ncpuʱ��Ƭ������ִ��ʱ��Ϊ"<<cpu<<endl;
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
			cout<<"��������Ϊ��"<<endl;
			
		}
//////////////////////////////////////////////////////////�ȴ����еĵ�һ�����̲��뵽��������
		if(1==QueueEmpty(wait))//�ȴ����зǿ�
		{
			int j=rand()%2;
			if(j==1)
			{
				DeQueue ( wait,temp);
				temp.state = 1;
				EnQueue(ok,temp);
			}
		}
	////////////////////////////////////////////////////////////����������
		cout<<setw(22)<<"������"<<setw(9)<<"״̬"<<setw(11)<<"���ȼ�"<<setw(11)<<"ִ��ʱ��"<<endl;
		cout<<"��������Ϊ��"<<endl;//��ӡ��������
		PrintQueue(ok);
		cout<<"�ȴ�����Ϊ��"<<endl;
		PrintQueue(wait);
	}
}
 void print(PCB &s)//��ӡ�������̵����
{
	cout<<setw(20)<<s.name<<setw(10)<<s.state<<setw(10)<<s.prior<<setw(10)<<s.time<<endl;
}
 int main()
{
	int i,j,m,b,k;
	char c;
    char n[11]="ABCDEFGHIJ";
	LinkQueue ok,wait,run;
	cout<<"ʮ���������Ϊ��"<<endl; 
	cout<<setw(22)<<"������"<<setw(9)<<"״̬"<<setw(11)<<"���ȼ�"<<setw(11)<<"ִ��ʱ��"<<endl;
	do
	{
		InitQueue (ok);//��ʼ���ȴ����к;�������
		InitQueue (wait);
		InitQueue (run);
		for(i=0;i<10;i++)//�������10������ �������� ״̬ ���ȼ� ִ������ʱ�� 
		{
			PCB p;
			p.name=n[i];//����Ϊ1-10 
			j=rand()%2;//���������0��1,��Ϊ1�������,��Ϊ0��ȴ�
			p.state=j;
			m=rand()%10;//���������0-9 
			p.prior=m+1;//�����1-10��ʾ���ȼ� 
			p.time=rand()%50+1;
			if(j==1)
				EnQueue(ok,p);
			else	
				EnQueue(wait,p);
			print(p);//��ӡ�������� 
		}
		cout<<"��������Ϊ��"<<endl;
		PrintQueue(ok);
		cout<<"�ȴ�����Ϊ�� "<<endl;
		PrintQueue(wait);
		cout<<endl<<endl;
		cout<<"�����͵ȴ������Ѿ�����,��ѡ����ϣ���ĵ����㷨:     "<<endl;
		cout<<"   1.�����ȳ������㷨                              "<<endl;
		cout<<"   2.�����������ĵ����㷨                          "<<endl;
		cout<<"   3.���ִ��ʱ������㷨                          "<<endl;
		cout<<"   ����������1-3ѡ����:";
		cin>>b;
		switch(b)
		{
			case 1:fifo(wait,ok,run);break;
			case 2:prior(wait,ok,run);break;
			case 3:shorttime(wait,ok,run);break;
			default:cout<<"��������"<<endl;
		}
		cout<<endl<<endl<<"����ִ������y,�˳�ϵͳ����n��"<<endl;
		cin>>c;
	}while(c=='Y'||c=='y');///////////////////////////////////////////end do
	system("cls");//��ҳ 
	return 0;
}

