#include<iostream>
#include<math.h>
#include<string>
using namespace std;
const int maxl=100;
struct etype
{
	int age;
	string name;
};
//------------------------------------------------
struct list 
{
	etype ele[maxl];
	int last;
};
//------------------------------------------------------
void ins(etype x,int p,list & l)
{
	if(l.last>maxl)
		cout<<"error\n";
	else if(p<0 || p>l.last)
		cout<<"eror\n";
	else
	{
		for(int i=l.last;i>=p;i--)
			l.ele[i+1]=l.ele[i];
		l.last++;
		l.ele[p]=x;
	}
}
//------------------------------------------------------
void del(int p,list & l)
{
	if(p<0 || p>l.last)
		cout<<"error\n";
	else
	{
		for(int i=p;i<l.last;i++)
			l.ele[i]=l.ele[i+1];
		l.last--;
	}
}
//------------------------------------------------------
etype re(int p,list l)
{
	if(p<0 || p>l.last)
	{
		cout<<"error\n";
	}
	else
		return l.ele[p];
}
//--------------------------------------------------
int loc(etype e,list l)
{
	for(int i=0;i<l.last;i++)
	{
		if((l.ele[i].name==e.name) && (l.ele[i].age==e.age))
		{
			return i;
		}
		else
			return l.last;
	}
}
//-------------------------------------------------------
void set(list & l)
{
	cout<<"n=";
	cin>>l.last;
	cout<<"enter el:\n";
	for(int i=0;i<l.last;i++)
	{
		cout<<"Name:"; cin>>l.ele[i].name;
		cout<<"age:"; cin>>l.ele[i].age;
	}
}
//-------------------------------------------------------------
void dis(list l)
{
	for(int i=0;i<l.last;i++)
	{
		cout<<"name:"<<l.ele[i].name<<endl;
		cout<<"age:"<<l.ele[i].age<<endl;
	}
}
int END(list l)
{
	return l.last;
}
//--------------------------------------------
void jo(list & l1,list & l2)
{
	if(END(l1)+END(l2)>maxl)
		cout<<"Error\n";
	else
	{
		for(int i=0;i<l2.last;i++)
		{
			ins(re(i,l2),END(l1),l1);
		}
	}
}
//-------------------------------------------
void co(etype x,list l)
{
	int c=0;
	for(int i=0;i<l.last;i++)
	{
		if(re(i,l).name==x.name && re(i,l).age==x.age)
		{
			c++;
		}
	}
}
void main()
{
	list l,q,w;
	etype e,x;
	set(l);
	set(q);
	jo(l,q);
	cout<<"L1\n";
	dis(l);
	cout<<"L2\n";
	dis(q);


	system("pause");
}