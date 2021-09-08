#include<iostream>
#include<string>
using namespace std;

struct etype{
	string name;
	int id;
};

struct cellType{
	etype element;
	cellType* next;
};

struct Queue{
	cellType* front;
	cellType* rear;
	Queue(){
		front=rear=new cellType;
	}
};

bool Empty(Queue*q){
	if(q->front==q->rear)
		return true;
	return false;
}

void makenull(Queue*q){
	q->front=new cellType;
	q->front->next=NULL;
	q->rear=q->front;
}

void enqueue(etype x,Queue*q){
	q->rear->next = new cellType;
	q->rear=q->rear->next;
	q->rear->next=NULL;
	q->rear->element=x;
}



void dequeue(Queue*&q)
{
	if(Empty(q)){
		cout<<"The List is Empty !/n";
	}
	else{
		q->front->next=q->front->next->next;
	}
}

etype Front(Queue*q){
	if(Empty(q))
		{
			cout<<"Queue is Empty \n";
			return etype();
		}
	else{
		return q->front->next->element;
	}
}

etype Rear(Queue*q){
	if(Empty(q))
		{
			cout<<"Queue is Empty \n";
			return etype();
		}
	else{
		return q->rear->element;
	}
}

void Dis(Queue *q)
{
	int c=0;
	cellType*cur=q->front->next;
	while(cur){
		cout<<cur->element.name<<"\t"<<cur->element.id<<"\n";
		cur=cur->next;
		c++;
	}
	cout<<"The number of elements : \t"<<c<<endl;
	cout<<"\n-------------------------------\n";
}

void main(){

	Queue *q=new Queue;int n;etype e;
	Queue *z=new Queue;
	etype f;
	int cou=0;
	
	cout<<"Enter the number of Records --> ";cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Name --> ";cin>>e.name;
		cout<<"Enter ID --> ";cin>>e.id;
		enqueue(e,q);
	}
	Dis(q);
	
	
	cellType*cu=q->front->next;
	while(cu){
		if(cu->element.id<20){
	cu=cu->next;
		}
	
		else{
			enqueue(cu->element,z);
			cu=cu->next;
	}
	}
	if(!Empty(z)){
	cout<<"-------ID greater than 20--------\n"<<endl;
	Dis(z);
	}
	else{
		cout<<"No people with age greater than 20 !\n"<<endl;
	}
	int d=n/2;
	cout<<"--------Add at the middle-------- "<<endl;
	cout<<"Enter Name --> ";cin>>f.name;
	cout<<"Enter ID --> ";cin>>f.id;
	cellType*v=q->front->next;
	while(v){
	cou++;
	if(cou==d){
		cellType* temp=v->next;
		v->next = new cellType;
		v->next->next=temp;
		v->next->element=f;
	}
	else
		v=v->next;
	}
	Dis(q);
	system("pause");
}
