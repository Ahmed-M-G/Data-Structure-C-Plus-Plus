#include<iostream>
#include<string>
using namespace std;
//-----------------------------------
struct etype
{
	int age;
	string name;
};
//---------------------------------
struct cell
{
	etype element;
	cell *next;
};
//----------------------------------
struct Queue
{
	cell *front;
	cell *rear;
};
//-------------- NEW ---------------------
void newq(cell *&p)
{
	p = new cell;
	p->element.name=" ";
	p->element.age=0;
	p->next=NULL;
}
//------------ MakeNull ---------------------------
void MakeNull(Queue & q)
{
	newq(q.front);
	q.rear=q.front;
}
//------------------------------------
int Empty(Queue q)
{
	if(q.front == q.rear)
		return 1;
	else
		return 0;
}
//-------------------------------------
void enqueue(Queue &q,etype x)
{
	newq(q.rear->next);
	q.rear=q.rear->next;
	q.rear->next=NULL;
	q.rear->element.name=x.name;
	q.rear->element.age=x.age;
}
//-----------------------------------------
void dequeue(Queue &q)
{
	if (Empty(q))
	{
		cout<<"Queue is Empty\n";
	}
	else if(q.front->next == q.rear)
	{
		cell *temp;
		temp=q.front;
		q.rear=q.front->next;
		delete(temp);
	}
	else 
		q.front->next=q.front->next->next;
}
//----------------------------------------
etype FRONT(Queue q)
{
	if(Empty(q))
		cout<<"error";
	else
		return q.front->next->element;
}
//-----------------------------------------
void display(Queue q)
{
	if(Empty(q))
		cout<<"EMPTY\n";
	else
	{
		cell * p=q.front->next;
		while(p != q.rear)
		{
			cout<<"Name:"<<p->element.name<<"\n";
			cout<<"AGE:"<<p->element.age<<endl;
			p=p->next;
		}
		cout<<"Name:"<<p->element.name<<endl;
		cout<<"AGE:"<<p->element.age<<endl;
	}
}
//-----------------------------------------------------------------------------
void main()
{
	Queue Q;
	etype x;
	int n;
	cout<<"NULL:";
	MakeNull(Q);
	display(Q);
	cout<<"enter Size:"; cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter elements";
		cout<<"name :"; cin>>x.name;
		cout<<"Age:"; cin>>x.age;
		enqueue(Q,x);
	}
	display(Q);
	dequeue(Q);
	display(Q);
	cout<<"FRONT => NAME:"<<FRONT(Q).name<<endl;
	cout<<"FRONT => AGE:"<<FRONT(Q).age<<endl;
	system("pause");
}