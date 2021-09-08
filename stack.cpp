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
etype Top (stack s)
{
	etype e;
	if(Empty(s))
		return e;
	else 
		return s.element[s.top];
}
//----------------------------------
void PUSH(stack & s,etype x)
{
	if(s.top==0)
		cout<<"stack is FULL\n";
	else
	{
		s.top=s.top-1;
		s.element[s.top]=x;
		//s.element[s.top].name=x.name;
		//s.element[s.top].age=x.age;
	}
}
//--------------------------------
void POP(stack & s)
{
	if(Empty(s))
		cout<<"the stack is EMPTY\n";
	else
		s.top=s.top+1;
}
//-------------------------------
void display(stack s)
{
	for(int i=s.top;i<maxLength;i++)
	{
		cout<<"==========================================\n";
		cout<<"NAME: "<<s.element[i].name<<endl;
		cout<<"AGE: " <<s.element[i].age<<endl;
		cout<<"==========================================\n";
	}
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
		PUSH(x,e);
	}
	display(x);
	cout<<"///////////////////////////////////////////////////////////"<<endl;
	POP(x);
	display(x);
	cout<<"///////////////////////////////////////////////////////////"<<endl;
	w=Top(x);
	cout<<"TOP.name :"<<w.name<<endl<<"TOP.Age :"<<w.age<<endl;
	cout<<"///////////////////////////////////////////////////////////"<<endl;
	cout<<"check stack if empty or not EMPTY :"<<endl<<Empty(x)<<endl;
	cout<<"///////////////////////////////////////////////////////////"<<endl;
	cout<<"distroy my STACK :\n";
	MakeNull(x);
	display(x);

	system("pause");
}