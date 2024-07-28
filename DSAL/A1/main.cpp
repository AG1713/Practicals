#include<iostream>
using namespace std;

class linear_probing{
	int hashtable[10];
	int flag[10];
	
	public:
		linear_probing(){
			for(int i=0;i<10;i++){
				flag[i]=0;
			}
		}
		
	void insert(int key){
		int loc=key%10;
		
		for(int i=0;i<10;i++){
			if(flag[loc]==0){
				hashtable[loc]=key;
				flag[loc]=1;
				return;
			}
			else{
				loc=(loc+1)%10;
			}
			
		}
	}
	bool search(int key){
		int loc=key%10;
		
		for(int i=0;i<10;i++){
			if((flag[loc]==1) && hashtable[loc]==key){
				return true;
			}
		}
	}
	
	void display(){
		for(int i=0;i<10;i++){
			cout<<i<<"-->";
			if(flag[i]==1){
				cout<<hashtable[i]<<endl;	
			}
			else{
				cout<<"----"<<endl;
			}
		}
		
	}
};


int main(){
	linear_probing lb;
	int choice;
	
	while(true){
	cout<<"          Menu          "<<endl;
	cout<<"1. Insert"<<endl;
	cout<<"2. Search"<<endl;
	cout<<"3. Display"<<endl;
	cout<<"4. Exit"<<endl;
	
	cout<<"Enter the Choice: "<<endl;
	cin>>choice;
	
	switch(choice){
		case 1:{
			int val;
			
			cout<<"Enter the value of key:"<<endl;
			cin>>val;
			
			lb.insert(val);
			break;	
		}
		case 2:{
			int val;
			cout<<"Enter the value of key:"<<endl;
			cin>>val;
			
			cout<<lb.search(val)<<endl; 
			break;
		}
		case 3:{
			cout<<"Display is:"<<endl;
			cout<<"-------------------------"<<endl;
			lb.display();
			cout<<"-------------------------"<<endl;
			break;
		}
		case 4:{
			break;
		}
		default:{
			cout<<"Invalid choice"<<endl;
			break;
		}
		
	}
	if(choice==4){
		cout<<"Exiting..."<<endl;
		break;
	}	
	}
	
	return 0;
	
}
