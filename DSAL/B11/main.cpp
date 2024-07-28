#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node{
	node *left;
	string keyword;
	string meaning;
	node *right;
};


class Dictionary{
	
	public:
	node *root;

		
	Dictionary(){
		root = NULL;
	}
	
	
	void insert(string key, string m){
		if(root == NULL){
			// If tree is empty
			root = new node;
			root->keyword = key;
			root->meaning = m;
			root->left = NULL;
			root->right = NULL;
			return;
		}
		// If tree is not empty...
		
		node *temp = root;
		node *p = new node;
		p->keyword = key;
		p->meaning = m;
		p->left = NULL;
		p->right = NULL;
		
		while(temp != NULL){
			
			if(temp->keyword == key){
				return;
			}
			else if(temp->keyword > key){
				if(temp->left == NULL){
					temp->left = p;
					return;
				}
				temp = temp->left;
			}
			else{
				if(temp->right == NULL){
					temp->right = p;
					return;
				}
				temp = temp->right;
			}
			
			
		}
	}
		
	void create(){
		int num;
		string key;
		string m;
		cout<<"Enter the number of words : ";
		cin>>num;
		
		for (int i=0 ; i<num ; i++){
			cout<<"Enter word of keyword no. "<<i+1<<" : ";
			cin>>key;
			cout<<"Enter meaning for the word : ";
			cin>>m;
			
			insert(key, m);
		}
							
	}
	
	void inorder(node *t){
		if(t==NULL){
			return;
		}
			inorder(t->left);
			cout<<t->keyword<<' '<<t->meaning<<' ';
			inorder(t->right);
		
	}
		
	string search(string key){
		node *temp = root;
		
		while(temp != NULL){
			if(temp->keyword == key){
				return temp->meaning;
			}
			else if(temp->keyword > key){
				temp = temp->left;
			}
			else{
				temp = temp->right;
			}
		
		}
		return "No word found";
	}
	
	bool update(string key, string m){
		node *temp = root;
		
		while(temp != NULL){
			if(temp->keyword == key){
				temp->meaning = m;
				
				
				return true;
			}
			else if(temp->keyword > key){
				temp = temp->left;
			}
			else{
				temp = temp->right;
			}
		
		}
		return false;
		
		
	}
	
	
	node* min_node(node* temp){
		while(temp->left != NULL){
			temp = temp->left;
		}
		
		return temp;
	}
	
	node* max_node(node* temp){
		while(temp->right != NULL){
			temp = temp->right;
		}
		return temp;
	}
	
	
	
	void delete_node(string key){
		// Three cases
		// 1. left and right of node are NULL (leaf node)
		// 2. Either left or right of node is NULL
		// 3. Both left and right are not NULL
		
		
		node *temp = root;
		node *prev = NULL;
		
		while(temp != NULL){
			if(temp->keyword == key){
				// DELETION PROCESS BEGINS!
				if((temp->left == NULL) && (temp->right == NULL)){
					// If leaf node
					if(prev->left == temp){
						prev->left = NULL;
						delete temp;
						return;
					}
					else{
						prev->right = NULL;
						delete temp;
						return;
					}
				}
				
				
				else if((temp->left != NULL) && (temp->right == NULL)){
					if(prev->left == temp){
						prev->left = temp->left;
						delete temp;
						return;
					}
					else{
						prev->right = temp->left;
						delete temp;
						return;
					}
					
				}
				
				else if((temp->left == NULL) && (temp->right != NULL)){
					if(prev->left == temp){
						prev->left = temp->right;
						delete temp;
						return;
					}
					else{
						prev->right = temp->right;
						delete temp;
						return;
					}
					
				}
				
				else if((temp->left == NULL) && (temp->right != NULL)){
					node* replacement = max_node(temp->left);
					temp->keyword = replacement->keyword;
					temp->meaning = replacement->meaning;
					delete_node(replacement->keyword);
					return;
				}
				
				
				return;
				
			}
			else if(temp->keyword > key){
				prev = temp;
				temp = temp->left;
			}
			else{
				prev = temp;
				temp = temp->right;
			}
		
		}
		
	}
	
	
	
	
	
};




int main() {
	
	Dictionary d;
	int choice = 0;
	bool creation_flag = false;
	string k;
	string m;
	
	
	cout<<"Start of the program..."<<endl;
	while(choice != 7){
		cout<<"Operations :- "<<endl;
		
		cout<<"1. Create"<<endl;
		cout<<"2. Insert"<<endl;
		cout<<"3. Get meaning of"<<endl;
		cout<<"4. Display Dictionary"<<endl;
		cout<<"5. Update"<<endl;
		cout<<"6. Delete a word"<<endl;
		cout<<"7. Exit"<<endl;
		
		cout<<"Enter operation no. : ";
		cin>>choice;
		
		switch(choice){
			case 1:{
				if(creation_flag == false){
					d.create();
					break;
				}
				cout<<"Already created"<<endl;
				break;
			}
			case 2:{
				cout<<"Enter keyword : ";
				cin>>k;
				cout<<"Enter its meaning : ";
				cin>>m;
				
				d.insert(k, m);
				
				break;
			}
			case 3:{
				cout<<"Enter keyword : ";
				cin>>k;
				
				cout<<"Meaning - "<<d.search(k)<<endl;
				
				
				break;
			}
			case 4:{
				cout<<"Displaying..."<<endl;
				d.inorder(d.root);
				cout<<endl;
				
				break;
			}
			case 5:{
				cout<<"Enter the keyword : ";
				cin>>k;
				cout<<"Enter the new meaning : ";
				cin>>m;
				bool flag = d.update(k, m);
				
				if(flag){
					cout<<"Updated successfully"<<endl;				
				}
				else{
					cout<<"Node not found"<<endl;
				}
				
				break;
			}
			case 6:{
				cout<<"Enter keyword : ";
				cin>>k;
				
				d.delete_node(k);
				
				break;
			}
			case 7:{
				break;
			}
			default :{
				cout<<"Invalid choice"<<endl;
				break;
			}
			
			
		}
		
		
		
		cout<<endl;
		cout<<endl;
		
	}
	
	
	
	
	
	
	return 0;
}
