#include <iostream>
#include<string>
using namespace std;

struct etype{
    int ID;
    string name;
};

struct celltype{
    etype element;
    celltype* next;
};

typedef celltype* List;
typedef celltype* Pos;

List L;

Pos End(List L){
    Pos p=L;
    while(p->next){
        p=p->next;
    }
    return p;
}

void Insert(etype x,Pos p){
    Pos temp = p->next;
    p->next=new celltype;
    p->next->element=x;
    p->next->next=temp;
    temp=NULL;
    delete temp;
}

void Display(List L){
    Pos Cur=L->next;
    cout<<"------------------------------------\n";
    while(Cur){
        cout<<Cur->element.name<<"\t\t"<<Cur->element.ID<<"\n";
        Cur=Cur->next;
    }
}

void Delete(Pos p){
    p->next=p->next->next;
}

Pos Locate(etype x,List L){
    Pos cur=L;
    while(cur->next){
        if(cur->next->element.name==x.name&&cur->next->element.ID==x.ID)
            return cur;
        else
            cur=cur->next;
    }
    return cur;
}

etype Retrieve(Pos p){
    return p->element;
}

void Swap(List L)
{
    Insert(Retrieve(L->next),Locate(Retrieve(End(L)),L));
    Delete(L);
    etype x=Retrieve(End(L));
    Delete(Locate(Retrieve(End(L)),L));
    Insert(x,L);
}

/*void Swap(List L){
    etype eFirst = Retrieve(L->next);
    etype eLast = Retrieve(End(L));
    Insert(eLast,L);
    Pos q = L;
    while(q->next->next != NULL){
    q = q->next;
    }
    Delete(q);
    Insert(eFirst,End(L));
    Delete(L->next);
}*/

void Sort(List L){
	Pos p,q,cur,temp;
	p=L;
	while(p){
		cur=p->next;
		while(cur){
			if(cur->element.ID<=p->element.ID){
				temp=cur;
				q=Locate(Retrieve(cur),L);
				q->next=cur->next;
				Insert(Retrieve(temp),Locate(Retrieve(p),L));
				cur=cur->next;
			}
			else
				cur=cur->next;
		}
		p=p->next;
	}
}



void main()
{
    L =new celltype;
    L->next=NULL;
    int n;
    etype x,b;
    cout<<"Enter the number of the records --> ";cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Enter the name --> ";cin>>x.name;
        cout<<"Enter the ID --> ";cin>>x.ID;
        Insert(x,End(L));
    }
    cout<<"The main List :\n";
    Display(L);
    //-----------------Insert At first------------------
    //Insert(x,L);
    //Display(L);
    //----------------------Delete The second --------------
   /* Delete(L->next);
    cout<<"After Deleting the Second : \n";
    Display(L);
    // ----------- Locate An element in the list -------
    cout<<"Enter the name u want to search --> ";cin>>x.name;
    cout<<"Enter the ID u want to search --> ";cin>>x.ID;
    if(Locate(x,L)!=End(L))
        cout<<"The element exist \n";
    else
        cout<<"The element does not exist\n";
    //-------------- Retrieve the 2nd element --------------
    x=Retrieve(L->next->next);
    cout<<"\n------------Retrieve the 2nd----------\n"<<x.name<<"\t\t"<<x.ID<<"\n";
    // ------------------------- Delete the last element --------
    Delete(Locate(Retrieve(End(L)),L));
    cout<<"After Deleting the Last : \n";
    Display(L);
    // -------------------Insert B after X ---------------
    cout<<"Enter the name u want to add after it --> ";cin>>x.name;
    cout<<"Enter the ID u want to add after it --> ";cin>>x.ID;
    if(Locate(x,L)!=End(L)){
        cout<<"Enter the name u want to insert --> ";cin>>b.name;
        cout<<"Enter the ID u want to insert --> ";cin>>b.ID;
        Insert(b,Locate(x,L)->next);
    }
    else{
        cout<<"Sorry x does n't exists\n";
    }
    cout<<"After Inserting the element : \n";
    Display(L);
    //--------------------Swap The first with the Last--------*/
    Swap(L);
    cout<<"After Swap the first and last elements : \n";
    Display(L);
    Sort(L);
    cout<<"After sorting according to ID : \n";
    Display(L);
    system("pause");
}

