#include <iostream>
#include <string>
using namespace std;
//-----------------------------------
struct etype
{
	int age;
	string name;
};
//--------------------------------------
struct cell
{
	etype element;
	cell *next;
};
//------------------------------------------
void insert(etype x,cell *p)
{
	cell *temp;
	temp=p->next;
	p->next=new cell;
	p->next->element.name=x.name;
	p->next->element.age=x.age;
	p->next->next=temp;
}
//------------------------------------------
cell* End(cell *L)
{
	while(L->next != NULL)
		L=L->next;
	return L;
}
//--------------------------------------------------
cell* locate (etype x,cell *l)
{
	cell *p;
	p=l;
	while (p->next != NULL)
	{
		if((p->next->element.name==x.name) && (p->next->element.age==x.age))
			return p->next;
		else 
	    p=p->next;
	}
		return p->next;
	
}
//-----------------------------------------------------------
etype retrieve(cell *p)
{
	return p->element;
}
//-------------------------------------------------------------
void delet(cell *p)
{
	p->next=p->next->next;
}
//------------------------------------------------------------
void RemoveLast(cell *p)
{
	delet(End(p));
}
//-------------------------------------------------------
void main()
{
	int s;
	etype x;
	cell *h=new cell;
	h->next=NULL;
	//----------------------------------------------------------
	cout<<"enter size:";
	cin>>s;
	//----------------------------------------------------------
	for(int i=0;i<s;i++)
	{
		cout<<"enter element "<<i<<" :\n";
		cin>>x.name>>x.age;
		insert(x,End(h));
	}
	//---------------------------------------------------------
	etype g;
	
	cout<<"enter element you want locat\n";
	cout<<"name:"; cin>>x.name;
	cout<<"age:";  cin>>x.age;
	cell *w=locate(x,h);
	if(w==NULL)
	{
	cout<<"It is NULL"<<endl;
	}
	else
	{
	cout<<w;
	}
	//---------------------------------------------------------
	cell* p= h;
	while(p->next!=NULL)
	{
		cout<<retrieve(p->next).name<<endl<<retrieve(p->next).age<<endl;
		p=p->next;
	}
	/*g=retrieve(w);
	cout<<"Locate:"<<g.name<<g.age<<endl;*/
	system("pause");

}