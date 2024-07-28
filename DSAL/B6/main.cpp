#include <iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

class BST{
	public:
		node* root;
		BST(){
			root=NULL;
		}
		
		void insert(int x)
		{
			if(root == NULL){
				root = new node;
				root->data = x;
				root->left = NULL;
				root->right = NULL;
			}
			else{
				node* m = new node;
				m->data = x;
				m->left = NULL;
				m->right = NULL;
				
				
				node* temp = root;
				while(temp != NULL)
				{
					if(temp->data == x)
					{
						return;
					}
					
					if((temp->data) > x)
					{
						if(temp->left == NULL)
						{
							temp->left = m;
							return;
						}
						temp = temp->left;
					}
					
					if((temp->data) < x)
					{
						if(temp->right == NULL)
						{
							temp->right = m;
							return;
						}
						temp = temp->right;
					}
				}
			}
		}
		
		void create(int arr[],int size){
			for (int i=0;i<size;i++){
				insert(arr[i]);
			}
		}
		
		void inorder(node* t){
			if(t != NULL)
			{
				inorder(t->left);
				cout << t->data <<" ";
				inorder(t->right);
			}
			
		}
		
		int min_node(){
			node* temp = root;
			
			while(temp->left != NULL){
				temp = temp->left;
			}
			
			return temp->data;
		}
		
		int max_node(){
			node* temp = root;
			
			while(temp->right != NULL){
				temp = temp->right;
			}
			return temp->data;
		}
		
		void mirror(node *n){
			if (n == NULL) return;
			
			mirror(n->left);
			mirror(n->right);
			swap(n->left, n->right);
			
		}
		
};


int main(){
	BST bin_tree;
	
	int choice = 0;
	int creation_flag = false;
	
	cout<<"Start the Program..."<<endl;
	while(choice !=6){
		cout<<" Operations "<<endl;
		cout<<"1. Create"<<endl;
		cout<<"2. Insert a Node"<<endl;
		cout<<"3. Display Inorder"<<endl;
		cout<<"4. Display Minimum Value"<<endl;
		cout<<"5. Display Maximum Value"<<endl;
		cout<<"6. Exit..."<<endl;
		cout<<"Enter Your Choice :"<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:{
				if(creation_flag == true){
					cout<<"Already Created"<<endl;
					break;
				}
				
				int num;
				cout<<"Enter the Number of Values ";
				cin>>num;
				
				int arr1[num];
				for(int i=0;i<num;i++){
					cout<<"Value No. "<<i+1<<" : ";
					cin>>arr1[i];
				}
				
				bin_tree.create(arr1,num);
				break;
			}
			
			case 2:{
				int value;
				cout<<"Enter the Value : ";
				cin>>value;
				
				bin_tree.insert(value);
				break;
			}
			
			case 3:{
				bin_tree.inorder(bin_tree.root);
				cout<<endl;
				break;
			}
			
			case 4:{
				cout<<"Minimum No. : "<<bin_tree.min_node()<<endl;
				break;
			}
			
			case 5:{
				cout<<"Maximum No. : "<<bin_tree.max_node();
				break;
			}
			
			case 6:{
				cout<<"Exiting the Program...";
				break;
			}
			case 7:{
				cout<<"Mirroring";
				bin_tree.mirror(bin_tree.root);
				break;
			}
		}
		
		cout<<endl;
		cout<<endl;
	}
	return 0;
}
