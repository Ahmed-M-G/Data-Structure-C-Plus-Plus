#include <iostream>
#include <string>
using namespace std;

struct etype {

	string name;
	int age ;
             };

struct celltype {
   
	etype element;
	celltype* next ;

	celltype () {
	         next=NULL;
	  }   
    
	    
} ;  
    
struct queue {
      
	celltype* front ;
	celltype * rear ;  
	     
	queue (){
	front = new celltype() ;
	front -> next =NULL ;
	rear =front ;
	}
};



bool empty (queue q){

	if (q.front == q.rear )
		return true ;
	else 
		return false ;

}


void enqueue (etype x , queue &q) {

	q.rear -> next = new celltype() ;
	q.rear = q.rear->next ;
	q.rear->element= x ;


}

void dequeue (queue &q){

	if (empty(q)==true)
		cout << "erroe" ;
	else 
		q.front =q.front ->next ;

}

etype front (queue q){

	if (empty(q))
	    cout <<" error"  ;
	else 
		return q.front ->next->element ;


}


void display (queue q) {

	while (empty (q) == false ) {
        
		cout << front(q).name <<"=>"<< front(q).age<<endl ; 
	    dequeue(q) ;
	}
	 
}

int size (queue q) {
	
	int c=0 ;
	while (!empty (q) ) {
		c++ ; 
	    dequeue(q) ;
	}

	return c ;

}

void age_20 ( queue &q) {
	 int i ;
	 int s=size(q) ;

        for (i=0 ; i<s ; i++) 
		{ 
	      if (front(q).age>20 )
			  dequeue (q) ;
		  else 
			{  enqueue (front(q), q) ;
		       dequeue (q) ; }
	 	
	    }

}


void  enqueue_mid (etype x ,queue &q) {
	 int i ;
	 int s=size(q);

     	 for(i=0 ; i<s/2 ; i++) 
		 {
	           enqueue (front(q), q) ;
			   dequeue (q) ;	 
		 }

	 enqueue (x,q) ;

		  for(i=0 ; i<s/2 ; i++) 
		 {
	           enqueue (front(q), q) ;
			   dequeue (q) ;	 
		 }



}



void main () {

	etype x ;
	queue z ;
	int n,i ;
	cout<<"enter size=>" ; 
	cin>>n ;

	for (i=0 ; i<n ; i++) 
	    {
	    cin>>x.name>>x.age ;
		enqueue (x, z) ;
		}

	cout<<"my data=>" << endl;
	display (z) ;
	cout<<endl;
//3 a 1 b 2 c 3

	cout<<"my size=>" << size (z) << endl;

	cout<<" my data after edit " << endl; 
	age_20 (z);
	display (z);
	cout<<endl ;


	etype y ;
	y.name = "marwa" ;
	y.age = 20 ;

	cout<<" my data after enqueue in middle " << endl; 
	enqueue_mid (y,z) ;
	display (z);
	cout<<endl ;





system ("pause") ;
}