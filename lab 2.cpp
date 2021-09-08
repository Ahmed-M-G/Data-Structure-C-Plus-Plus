#include<iostream>
#include<string>
using namespace std;
struct etype
{
	string name;
	int age;
};
struct list
{
	etype el[50];
	int last;
};
void insert(etype x,int p,list & l)
{
	if(l.last>=50)
	{
		cout<<"error\n";
	}
	else if((p>l.last+1) || (p<0))
	{
		cout<<"error\n";
	}
	else 
	{
		for(l.last;l.last>p;l.last++)
		{
			l.el[p+1]=l.el[p];
			l.last=l.last+1;
			l.el[p]=x;
		}
	}
}
//-----------------------------------------------------------------
int End(list l)
{
	return l.last+1;
}
//----------------------------------------------------------------
void delet(int p,list & l)
{
	if((p>l.last)||(p<0))
	{
		cout<<"error\n";
	}
	else
	{
		l.last=l.last-1;
		for(l.last;l.last>p;l.last--)
		{
			l.el[p]=l.el[p+1];
		}
	}

}
//-------------------------------------------------------------------
etype re(int p,list l)
{
	etype x;
	x.name="";
	x.age=0;
	if((p>l.last)||(p<0))
	{
		cout<<"error\n";
	}
	else
	{
		//for(int i=0;i<50;i++)
			cout<<"name:"<<l.el[p].name<<endl<<"age:"<<l.el[p].age<<endl;
	}
	return x;
}
int locat(etype x,list l)
{
	for(int i=0;i<l.last;i++)
	{
		if(x.name==l.el[i].name && x.age==l.el[i].age)
		{
			return i;
		}
		else
		{
			return l.last+1;
		}
	}
}
//--------------------------------------------------------------------------------
void display(list l)
{
	for(int i=0;i<2;i++)
	{
		cout<<"name:"<<l.el[i].name<<endl<<"age:"<<l.el[i].age<<endl;
	}
}
void main()
{
	list s;
	etype x;
	/*s.last=-1;
	for(int i=0;i<2;i++)
	{	cin>>x.name;
	    cin>>x.age;
	insert(x,End(s),s);
	}*/
	cout<<"enter data:";
	for(int i=0;i<3;i++)
	{
		cin>>s.el[i].name>>s.el[i].age;
	}
	cout<<"end el:"<<End(s);
	delet(1,s);

	system("pause");
}