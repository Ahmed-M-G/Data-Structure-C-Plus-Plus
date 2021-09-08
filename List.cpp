#include<iostream>
#include<string>
using namespace std;
const int maxlength=100;

struct etype{
    char name[20];
    char address[50];
    int account;
};

struct List{
    etype e[maxlength];
    int last;
    List(){
        last=0;
    }
};

int END(List l){
    return l.last;
}

void Insert(etype x,int p,List &l){
    if(l.last>=maxlength){
        cout<<"Sorry The list is Full !\n";
    }
    else if(p>l.last||p<0){
        cout<<"Wrong Position !\n";
    }
    else{
        for(int q=l.last;q>p;q--){
            l.e[q+1]=l.e[q];
        }
        l.e[p]=x;
        l.last++;
    }
}

void Delete(int p,List &l){
    if(p>l.last||p<0){
        cout<<"Position Doesn't exist\n";
    }
    else{
        for(int q=p-1;q<l.last;q++){
            l.e[q]=l.e[q+1];
        }
        l.last--;
    }
}

void Display(List L){
    cout<<"Index\t\tName\t\tAddress\t\tNo\n";
    for(int i=0;i<L.last;i++){
        cout<<i+1<<"\t\t"<<L.e[i].name<<"\t\t"<<L.e[i].address<<"\t\t"<<L.e[i].account<<"\n";
    }
}

int Locate(etype x,List l){
    for(int q=0;q<l.last;q++){
        if(string(l.e[q].name)==string(x.name)&&string(l.e[q].address)==string(x.address)&&l.e[q].account==x.account){
            return q+1;
        }
    }
    cout<<"The element doesn't exist\n";
    return l.last+1;
}

etype Retrieve(int p,List l){
    if(p>l.last||p<0){
        cout<<"Wrong position !\n";
        return etype();
    }
    else{
        return l.e[p-1];
    }
}

void Join(List &l1,List &l2){
    for(int q=0;q<l1.last;q++){
        Insert(l1.e[q],l2.last,l2);
    }
}

int Count(etype x,List l){
    int coun=0;
    for(int q=0;q<l.last;q++){
        if(string(Retrieve(q+1,l).name)==string(x.name)&&string(Retrieve(q+1,l).address)==string(x.address)&&Retrieve(q+1,l).account==x.account){
            coun++;
        }
    }
    return coun;
}

int main()
{
    int numberOfElements,p;
    etype x;
    List L,L2;
    cout<<"Enter the number of elements --> ";cin>>numberOfElements;
    for(int i=0;i<numberOfElements;i++){
        cout<<"Enter the Name --> " ;cin>>x.name;
        cout<<"Enter the Address --> ";cin>>x.address;
        cout<<"Enter the number of Account --> ";cin>>x.account;
        Insert(x,i,L);
    }

    cout<<"\n------------------------------\n";
    Display(L);
    cout<<"\n------------------------------\n";

    cout<<"Enter the Name --> " ;cin>>x.name;
    cout<<"Enter the Address --> ";cin>>x.address;
    cout<<"Enter the number of Account --> ";cin>>x.account;
    cout<<"Enter the position --> ";cin>>p;

    Insert(x,p-1,L);

    cout<<"\n------------------------------\n";
    Display(L);
    cout<<"\n------------------------------\n";

    Insert(x,10,L);
    cout<<"\n------------------------------\n";

    cout<<"Enter the Number of element u want to delete --> ";cin>>p;
    Delete(p,L);

    cout<<"\n------------------------------\n";
    Display(L);
    cout<<"\n------------------------------\n\n------For The Search----------\n";
    cout<<"Enter the Name --> " ;cin>>x.name;
    cout<<"Enter the Address --> ";cin>>x.address;
    cout<<"Enter the number of Account --> ";cin>>x.account;
    cout<<Locate(x,L);
    cout<<"\n------------------------------\n\n------For The Retrieve----------\n";
    cout<<"Enter the position of the element u want to retrieve --> ";cin>>p;
    x=Retrieve(p,L);
    cout<<x.name<<"\t\t"<<x.address<<"\t\t"<<x.account<<endl;
    cout<<"\n------------------------------\n\n------Construct the Second List----------\n";
    cout<<"Enter the number of elements --> ";cin>>numberOfElements;
    for(int i=0;i<numberOfElements;i++){
        cout<<"Enter the Name --> " ;cin>>x.name;
        cout<<"Enter the Address --> ";cin>>x.address;
        cout<<"Enter the number of Account --> ";cin>>x.account;
        Insert(x,i,L2);
    }
    cout<<"\n------------------------------\n";
    Display(L2);
    cout<<"\n------------------------------\n";
    Join(L,L2);
    Display(L2);
    cout<<"\n------------------------------\n";
    cout<<L2.last;
    cout<<"\n------------------------------\n\n------For Count----------\n";
    cout<<"Enter the Name --> " ;cin>>x.name;
    cout<<"Enter the Address --> ";cin>>x.address;
    cout<<"Enter the number of Account --> ";cin>>x.account;
    cout<<Count(x,L2);
    return 0;
}
