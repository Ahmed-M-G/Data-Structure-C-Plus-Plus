#include<iostream>
#include<string>
using namespace std;
const int maxLength = 100;
//-----------------------------------
struct etype
{
	int age;
	string name;
};
//-----------------------------------
struct stack
{
	int top;
	etype element[maxLength];
};
//-----------------------------------
void MakeNull(stack & s)
{
	s.top=maxLength;
	cout<<"IS DONE\n";
}
//----------------------------------
bool Empty(stack s)
{
	if(s.top>maxLength)
		return true;
	else 
		return false;
}
//---------------------------------
etype Top(stack s)
{
	etype e;
	if(Empty(s))
		return e;
	else
		return s.element[s.top];
}
//-------------------------------
void ps(stack & s,etype e)
{
	if(s.top==0)
		cout<<"FULL\n";
	else
		s.top=s.top-1;
		s.element[s.top]=e;
}
//---------------------------------
void pop(stack & s)
{
	if(Empty(s))
		cout<<"EMPTY\n";
	else
		s.top=s.top+1;
}
//--------------------------------
void dis(stack s)
{
	for(int i=s.top;i<maxLength;i++)
	{
		cout<<"Name:"<<s.element[i].name<<endl;
		cout<<"AGE:"<<s.element[i].age<<endl;
	}
}
//--------------------------------------------------
void delfi(stack & s)
{
	stack q;
	etype e;
	while(!Empty(s))
	{
		e=Top(s);
		ps(q,e);
		pop(s);
	}
	pop(q);
	while(!Empty(q))
	{
		e=Top(q);
		ps(s,e);
		pop(q);
	}
}
//--------------------------------------
bool pa(stack s)
{
	stack w , q=s;
	etype e;
	while(!Empty(q))
	{
		e=Top(q);
		ps(w,e);
		pop(q);
	}
	while(!Empty(s))
	{
		if(Top(s).name == Top(w).name){
			pop(s);
			pop(w);
		}
		else
			return false;
	}
	return true;
}
void main()
{
	etype e,w;
	int n;
	stack x;
	//-------------------------------------------------
	MakeNull(x);
	//-------------------------------------------------
	cout<<"Enter the number of elements ="; cin>>n;
	//---------------------------------------------------
	for(int i=0;i<n;i++)
	{  
		cout<<"Name : "; cin>>e.name;
	    cout<<"age : "; cin>>e.age;
		ps(x,e);
	}
	dis(x);
	/*cout<<"///////////////////////////////////////////////////////////"<<endl;
	pop(x);
	dis(x);
	cout<<"///////////////////////////////////////////////////////////"<<endl;
	w=Top(x);
	cout<<"TOP.name :"<<w.name<<endl<<"TOP.Age :"<<w.age<<endl;
	cout<<"///////////////////////////////////////////////////////////"<<endl;
	cout<<"check stack if empty or not EMPTY :"<<endl<<Empty(x)<<endl;
	cout<<"///////////////////////////////////////////////////////////"<<endl;
	cout<<"distroy my STACK :\n";
	MakeNull(x);
	dis(x);*/
	cout<<"pal"<<pa(x)<<endl;
	system("pause");
}