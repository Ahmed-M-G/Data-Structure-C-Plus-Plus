#include<iostream>
#include<string>
using namespace std;
struct etype
{
	string name;
	int age;
};
struct qu
{
	int f,r;
	etype el[50];
};
int add(int i)
{
	return ((i+1)%50);
}
bool em(qu q)
{
	if(add(q.r)==q.f)
		return true;
	else 
		return false;
}
void MN(qu & q)
{
	q.f=0;
	q.r=50-1;
}
void en(etype e,qu & q)
{
	if(add(add(q.r))==q.f)
		cout<<"is full\n";
	else
	{
		q.r=add(q.r);
		q.el[q.r]=e;
	}
}
void de(qu & q)
{
	if(em(q))
		cout<<"empty\n";
	else
	{
		q.f=add(q.f);

	}
}
etype fr(qu q)
{
	return q.el[q.f];
}
void dis(qu q)
{
	while(!em(q))
	{
		cout<<"NAme:"<<fr(q).name<<"age:"<<fr(q).age<<endl;
		q.f=add(q.f);
	}
}
void main()
{
	qu a;
	etype w,r;
	int n;
	MN(a);
	cout<<"n:"; cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"NAme:"; cin>>w.name;
		cout<<"age:"; cin>>w.age;
		en(w,a);
	}
	dis(a);
	//de(a);
	//dis(a);
	r=fr(a);
	cout<<r.name<<endl;
	system("pause");
}