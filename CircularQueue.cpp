#include <iostream>
#include <string>
using namespace std;
const int maxLength =10;
struct etype{
    int ID;
    string name;
};

struct Queue{
    etype element[maxLength];
    int Front;
    int Rear;
    Queue(){
        Front=0;
        Rear=maxLength-1;
    }
};

int addOne(int i){
    if(i==maxLength-1) return 0;
    return ((i%(maxLength-1))+1);
}

bool Empty(Queue q){
    if(addOne(q.Rear)==q.Front){
        return true;
    }
    return false;
}

bool Full(Queue q){
    if(addOne(addOne(q.Rear))==q.Front){
        return true;
    }
    return false;
}

void makeNull(Queue & q){
    q.Front=0;
    q.Rear=maxLength-1;
}

void Enqueue(etype x,Queue & q){
    if(Full(q))
        cout<<"Queue is Full\n";
    else{
        q.Rear=addOne(q.Rear);
        q.element[q.Rear]=x;
    }
}

void Dequeue(Queue &q){
    if(Empty(q))
        cout<<"Queue is Empty\n";
    else{
        q.Front=addOne(q.Front);
    }
}
void dis(Queue q){
    if(!Empty(q)){
        for(int i=q.Front;;i=addOne(i)){
            cout<<q.element[i].ID<<"   "<<q.element[i].name<<"\n";
            if(i==q.Rear)
                break;
        }
    }
    else{
        cout<<"Empty Queue !\n";
    }
}


void main()
{
    Queue q;
    etype x;
    cout<<"Enter name : ";cin >>x.name;
    cout<<"Enter ID : ";cin>>x.ID;
    Enqueue(x,q);
    dis(q);
    cout<<"Enter name : ";cin >>x.name;
    cout<<"Enter ID : ";cin>>x.ID;
    Enqueue(x,q);
    dis(q);
    for(int i=0;i<5;i++){
            if(i==1) Dequeue(q);
        cout<<"Enter name : ";cin >>x.name;
        cout<<"Enter ID : ";cin>>x.ID;
        Enqueue(x,q);
        if(Full(q))
            cout<<q.Front<<"    "<<q.Rear<<"\n";
    }
    dis(q);
    cout<<"\n----------------0-------------------\n";
    Dequeue(q);
    dis(q);
    cout<<q.Front<<"    "<<q.Rear<<"\n";
    cout<<"\n-----------------1-------------------\n";
    Dequeue(q);
    dis(q);
    cout<<q.Front<<"    "<<q.Rear<<"\n";
    cout<<"\n----------------2--------------------\n";
    Dequeue(q);
    dis(q);
    cout<<q.Front<<"    "<<q.Rear<<"\n";
    cout<<"\n------------------3------------------\n";
    Enqueue(x,q);
    Dequeue(q);
    dis(q);
    cout<<q.Front<<"    "<<q.Rear<<"\n";
    cout<<"\n-----------------4-------------------\n";
    Dequeue(q);
    Enqueue(x,q);
    dis(q);
    cout<<q.Front<<"    "<<q.Rear<<"\n";
    cout<<"\n-----------------5-------------------\n";
    Enqueue(x,q);
    dis(q);
    cout<<q.Front<<"    "<<q.Rear<<"\n";
    cout<<"\n------------------6------------------\n";
    makeNull(q);
    cout<<q.Front<<"    "<<q.Rear<<"\n";
    Dequeue(q);
    cout<<q.Front<<"    "<<q.Rear<<"\n";
    system("pause");
}
