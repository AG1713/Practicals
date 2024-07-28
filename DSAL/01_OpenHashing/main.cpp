#include <iostream>
using namespace std;

struct node{
	int tele_num;
	node *next;
};


class openhashing{
	node *hashtable[10];
	
	public:
	openhashing(){
		for (int i=0 ; i<10 ; i++){
			hashtable[i] = NULL;
		}
	}
	
	void insert(int key){
		node *new_node = new node;
		new_node->tele_num = key;
		new_node->next = NULL;
		
		int loc = key%10;
		
		if(hashtable[loc] == NULL){
			hashtable[loc] = new_node;
		}
		else{
			node *temp = hashtable[loc];
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = new_node;
			
		}


	}
	
	bool search(int key){
		int loc = key%10;
		
		node *temp = hashtable[loc];
		
		int count = 0;
		
		while(temp != NULL){
			if(temp->tele_num == key){
				cout<<"count : "<<count<<endl;
				return true;
			}
			temp = temp->next;
			count++;
		}
		count++;
		cout<<"count : "<<count<<endl;
		return false;
	}
	
	void display(){
		for(int i=0 ; i<10 ; i++){
			node *temp = hashtable[i];
			cout<<i<<". ";
			
			if(temp==NULL){
				cout<<"NULL"<<" ";
			}
			
			while(temp != NULL){
				cout<<" --> "<<(temp->tele_num);
				temp = temp->next;
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	
};



int main() {
	openhashing directory;
	int choice;
	
	while(true){
		cout<<"      MENU         "<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Search"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"4. Exit"<<endl;
		
		cout<<"Enter choice : ";
		cin>>choice;
		
		switch(choice){
			case 1:{
				int val;
				
				cout<<"Enter value of Key :";
				cin>>val;
				
				directory.insert(val);
				break;
			}
			case 2:{
				int val;
				
				cout<<"Enter value of Key :";
				cin>>val;
				
				if(directory.search(val)){
					cout<<"Found"<<endl;
				}
				else{
					cout<<"Not found"<<endl;
				}
				break;
			}
			case 3:{
				cout<<"Displaying..."<<endl;
				cout<<"------------------------------------------------------------------"<<endl;
				directory.display();
				cout<<"------------------------------------------------------------------"<<endl;
				break;
			}
			case 4:{
				break;
			}
			default:{
				cout<<"Invalid Choice"<<endl;
				break;
			}
		}
		
		if(choice==4){
			cout<<"Exiting..."<<endl;
			break;
		}
		
		cout<<endl;
	}

	
	
	return 0;
}
