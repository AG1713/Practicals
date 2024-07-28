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
			f=-1;
			r=-1;
			return;
		}
		f=(f+1)%size;
		
		
	}
	else{
		cout<<"Cannot delete, queue is empty"<<endl;
	}
}


int main(){
    
    return 0;
}