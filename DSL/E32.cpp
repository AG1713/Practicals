// Question :-
// Pizza parlor accepting maximum M orders. Orders are served in first come first served
// basis. Order once placed cannot be cancelled. Write C++ program to simulate the system
// using circular queue using array.

# include<iostream>
using namespace std;

class C_Queue{
	int f; // This points the first element
	int r; // This points the next space to last element
	int size;
	int *a;
	
	public:
	C_Queue(int s){
		f=-1;
		r=-1;
		a = new int[s];
		size = s;
	}
	
	int if_full(){
		if((r+1)%size==f){
			return 1;
		}
		return 0;
	}
	
	int if_emt(){
		if((f==-1)&&(r==-1)){
			return 1;
		}
		return 0;
	}
	
	void q_add(int id); // To not make these an  inline function, we defined this outside
	void q_rem(); // To not make these an  inline function, we defined this outside
	
	void display(){
		int i=f;
		
		if(f==-1){
			cout<<"Queue :{}"<<endl;
			return;
		}
		
		cout<<"Queue : {";
		while(true){
			cout<<a[i]<<" ";
			
			// Breaking condition
			if(i==r){
				break;
			}
			i = (i+1)%size;
		}
		cout<<"}"<<endl;
	}
	
	
};

void C_Queue :: q_add(int id){
	if(if_full()!=1){
		if((f==-1)&&(r==-1)){
			f=(f+1)%size;
			r=(r+1)%size;
			a[r] = id;
		}
		else{
			r=(r+1)%size;
			a[r]=id;
		}
	}
	else{
		cout<<"Cannot add, queue is full"<<endl;
	}
}

void C_Queue :: q_rem(){
	if(if_emt()!=1){
		if(f==r){
			cout<<"Deleted id:"<<a[f]<<endl;
			f=-1;
			r=-1;
			return;
		}
		
		cout<<"Deleted id:"<<a[f]<<endl;
		f=(f+1)%size;
		
		
	}
	else{
		cout<<"Cannot delete, queue is empty"<<endl;
	}
}


int main(){
	C_Queue pizza(5);
	int choice; // This is operation number
	int id; // To add an element, we need a temporary variable, which is this
	
	cout<<"Starting..."<<endl;
	while(true){
		cout<<"Operations :"<<endl;
		cout<<"1. Add an order"<<endl;
		cout<<"2. Serve an order"<<endl;
		cout<<"3. Display the queue"<<endl;
		cout<<"4. Check if queue is full"<<endl;
		cout<<"5. Check if queue is empty"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Enter operaton number :";
		cin>>choice;
		
		if(choice==1){
			cout<<"Enter id:";
			cin>>id;
			pizza.q_add(id);
		}
		if(choice==2){
			pizza.q_rem();
		}
		if(choice==3){
			pizza.display();
		}
		if(choice==4){
			if(pizza.if_full()==1){
				cout<<"The Queue is full"<<endl;
			}
			else{
				cout<<"The Queue is not full"<<endl;
			}
		}
		if(choice==5){
			if(pizza.if_emt()==1){
				cout<<"The Queue is empty"<<endl;
			}
			else{
				cout<<"The Queue is not empty"<<endl;
			}
		}
		if(choice==6){
			cout<<"Exiting..."<<endl;
			break;
		}
		
		cout<<endl;
		cout<<endl;
	}
	
	
}