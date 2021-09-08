#include <iostream>
#include <string>
using namespace std;
const int maxlength=50;

struct etype{
    int ID;
    int Bi;
    string name;
    etype(){
        ID=0;
        Bi=0;
        name="";
    }
};

struct Stack{
    etype elements[maxlength];
    int top;
    Stack(){
        top=maxlength;
    }
};

bool Empty(Stack s){
    if(s.top>=maxlength)
    {
        return true;
    }
    else
        return false;
}

void MakeNull(Stack &s){
    s.top=maxlength;
}

etype Top(Stack s){
    etype x;
    x.name="";
    x.ID=0;
    if(Empty(s)){
        cout<<"The stack is Empty\n";
        return x;
    }
    else{
        return s.elements[s.top];
    }
}

void Push(etype x,Stack &s){
    if(s.top==0){
        cout<<"The Stack is Full\n";
    }
    else{
        s.top--;
        s.elements[s.top]=x;
    }
}

void Pop(Stack &s){
    if(!Empty(s)){
        s.top++;
    }
    else{
        cout<<"The Stack is Empty\n";
    }
}

void Display(Stack s){
    Stack q;
    etype e;
    int i=1;
    while(!Empty(s)){
        e=Top(s);
        Push(e,q);
        Pop(s);
    }
    while(!Empty(q)){
        cout<<i<<"- Name : "<<q.elements[q.top].name<<"\tID : "<<q.elements[q.top].ID<<"\n";
        Pop(q);
        i++;
    }
}

void DisplayBi(Stack s){
    Stack q;
    etype e;
    while(!Empty(s)){
        //e=Top(s);
        //Push(e,q);
        cout<<s.elements[s.top].Bi<<" ";
        Pop(s);
    }
    /*while(!Empty(q)){
        cout<<q.elements[q.top].Bi<<" ";
        Pop(q);
    }*/
}

void DeleteFirst(Stack &s){
    Stack q;
    etype e;
    while(!Empty(s)){
        e=Top(s);
        Push(e,q);
        Pop(s);
    }
    Pop(q);
    while(!Empty(q)){
        e=Top(q);
        Push(e,s);
        Pop(q);
    }
}

void DeleteAfter(Stack &s,etype y){
    Stack q;
    etype e;
    int i=0;
    while(!Empty(s)){
        e=Top(s);
        Push(e,q);
        Pop(s);
    }

    while(!Empty(q)){
        e=Top(q);
        if(y.name==e.name&&i==0)
        {
            Pop(q);
            i++;
        }
        Push(e,s);
        Pop(q);
    }
    if(i==0){
        cout<<"The element Doesn't Exist\n";
    }
}

void ConvDecitoBin(Stack &s,int r){
    etype x;
    int z=r%2;
    do{
        x.Bi=z;
        Push(x,s);
        z=(r/2)%2;
    }while(r=r/2);	
}

bool Palindrom(string st){
    Stack s,q;
    etype e;

    for(int i=0;i<st.length();i++){
        e.name=st[i];
        Push(e,s);
    }
    if(s.top==maxlength-1)
        return false;
    while(1){
        e=Top(s);
        Push(e,q);
        Pop(s);
        if(s.top==q.top-1)
            {
                Pop(s);
                break;
            }
        else if(s.top==q.top)
            break;
    }

    while(Top(s).name==Top(q).name&&!Empty(s)){
        Pop(s);
        Pop(q);
        if(Empty(s))
            break;
        if(Empty(q))
            break;
    }
    if(Empty(s)&&Empty(q))
        return true;
    else
        return false;
}

int main()
{
    int n,Binum;
    Stack S,BiSt;
    etype x;
    string str;
    cout<<"Enter The number of Records --> ";cin>>n;
    for (int i=0;i<n;i++){
        cout<<"Enter Name --> ";cin>>x.name;
        cout<<"Enter ID --> ";cin>>x.ID;
        Push(x,S);
    }
    cout<<"\n----------Display----------\n";
    Display(S);
    cout<<"\n----------Display After Pop The Last Element----------\n";
    Pop(S);
    Display(S);
    cout<<"\n----------Display After Delete The First Element----------\n";
    DeleteFirst(S);
    Display(S);
    cout<<"\n----------Delete element After y----------\n";
    cout<<"Enter Name u want to delete after --> ";cin>>x.name;
    DeleteAfter(S,x);
    Display(S);
    cout<<"\n----------Convert Decimal to Binary----------\n";
    cout<<"Enter the number u want to convert --> ";cin>>Binum;
    ConvDecitoBin(BiSt,Binum);
    DisplayBi(BiSt);
    cout<<"\n----------PalinDrome----------\n";
    cout<<"Enter String : ";cin>>str;
    if(Palindrom(str))
        cout<<"Palindrome\n";
    else
        cout<<"not\n";
    return 0;
}
