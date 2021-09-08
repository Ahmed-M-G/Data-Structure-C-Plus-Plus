#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxLength = 100;
//-----------------------------------
struct etype
{
	int age;
	string name;
};
//------------------------------------------------
struct list
{
	etype element[maxLength];
	int last;
};
//--------------------------------------------------------
void insert(etype x, int p, list & l)
{
	if (l.last >= maxLength)
		cout << "Error \n";
	else if (p > l.last  || p < 0)
		cout << "Error \n";
	else
	{
		for (int i = l.last; i >= p; i--)
		{
			l.element[i + 1] = l.element[i];
		}
		l.last++;
		l.element[p] = x;
	}
}
//-----------------------------------------------------------
void del(int p, list & l)
{
	if (p < 0 || p > l.last )
		cout << "Error";
	else
	{
		for (int i = p; i < l.last; i++)
		{
			l.element[i] = l.element[i+1];
		}
		l.last--;
	}
}
//---------------------------------------------------------------
etype retrieve(int p, list & l)
{
	if (p > l.last || p < 0)
		cout << "Error";
	else
		return l.element[p];
}
//-------------------------------------------------------------
int locate(etype x,list l)
{
	for(int i=0;i<l.last;i++)
	{
		if(x.name==l.element[i].name && x.age==l.element[i].age)
		{
			return i;
		}
		else
		{
			return l.last;
		}
	}
}
//---------------------------------------------------------------------------
void input(list & l)
{
	cout << "Enter the size of the array : ";
	cin >> l.last;
	cout << "Enter the array elements : \n";
	for (int i = 0; i < l.last; i++)
	{
		cout << "Name : ";
		cin >> l.element[i].name;
		cout << "Age : ";
		cin >> l.element[i].age;
	}
}
//----------------------------------------------------------------------------
void display(list & l)
{
	for (int i = 0; i < l.last; i++)
	{
		cout << "Name : " << l.element[i].name << endl;
		cout << "Age : " << l.element[i].age << endl;
	}
}
//---------------------------------------------------------------------------------
int End(list l)
{
	return l.last;
}
//------------------------------------------------------------------------------------
void join (list l1,list l2)
{
	if(maxLength > End(l1)+End(l2))
	{
		for(int i=0;i<=l2.last;i++)
		{
			insert(retrieve(i, l2),End(l1),l1);
		}
	}
}
//--------------------------------------------------------------------------------
int count(etype x,list l)
{
	int f,c=0;
	etype e;
	f=locate(x,l);
	c++;
	for(int i=f+1;i<=l.last;i++)
	{
		e=retrieve(i,l);
		if(e.name==x.name && e.age==x.age)
		{
			c++;
		}
	}
	return c;
}
void main()
{
	list L,s;
	etype e, a;
	int insertP, delP, retP;
	input (L);
	//display (L);
	cout << "Enter the element you want to insernt :" << endl;
	cout << "Name : "; cin >> e.name;
	cout << "Age : "; cin >> e.age;
	cout << "Enter the position you want to insert into :";
	cin >> insertP;
	insert(e, insertP, L);
	display (L);
	cout << "Enter the position you want to delete : ";
	cin >> delP;
	del(delP, L);
	display (L);
	cout << "Enter the position of the element you want to retrieve :";
	cin >> retP;
	cout << "Name : " << retrieve(retP, L).name << endl;
	cout << "Age : " << retrieve(retP, L).age << endl;
	cout << "Enter the element you want to locate : \n";
	cout << "Name : "; cin >> a.name;
	cout << "Age : "; cin >> a.age;
	cout << locate(a, L);
	cout<<" enter element you want count: \n ";
	cout << "Name : "; cin >> e.name;
	cout << "Age : "; cin >> e.age;
	cout<<"count:"<<count(e,L);
	cout<<"end"<<End(L)<<endl;
	system ("pause");
}