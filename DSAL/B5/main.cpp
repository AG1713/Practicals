#include <iostream>
using namespace std;


struct node{
	string label;
	node *child[50];
	int count; // Stores the count of the children
};


// Assuming the heirarchy is Book (Only one) --> Chapters --> Sections --> Subsections
class Tree{
	node *root;
	
	public:
	Tree(){
		root = NULL;
	}
	
	void insert(){
		root = new node;
		
		cout<<"Enter name of the book : ";
		getline(cin >> ws, root->label);
		
		cout<<"Enter the no. of chapters : ";
		cin>>(root->count);
		
		for (int i=0 ; i<root->count ; i++){
			root->child[i] = new node;
			cout<<"Enter name of the chapter "<<i+1<<" : ";
			getline(cin >> ws, root->child[i]->label);
			
			cout<<"Enter the number of sections : ";
			cin>>root->child[i]->count;
			for (int j=0 ; j<root->child[i]->count ; j++){
				root->child[i]->child[j] = new node;
				cout<<"Enter the name of the Section "<<j+1<<" : ";
				getline(cin >> ws, root->child[i]->child[j]->label);
				
				cout<<"Enter the number of subsections : ";
				cin>>root->child[i]->child[j]->count;
				
				for (int k=0 ; k<root->child[i]->child[j]->count ; k++){
					root->child[i]->child[j]->child[k] = new node;
					cout<<"Enter the name of the subsection "<<k+1<<" : ";
					getline(cin >> ws, root->child[i]->child[j]->child[k]->label);
				}
				
			}
			
		}
		
	}
	
	void display(){
		cout<<"Heirarchy of the book"<<endl;
		
		cout<<root->label<<endl;
		for (int i=0 ; i<root->count ; i++){
			cout<<"-->"<<root->child[i]->label<<endl;
			
			for (int j=0 ; j<root->child[i]->count ; j++){
				cout<<"---->"<<root->child[i]->child[j]->label<<endl;
				
				for (int k=0 ; k<root->child[i]->child[j]->count ; k++){
					cout<<"------>"<<root->child[i]->child[j]->child[k]->label<<endl;
				}
			}
		}
	}
	
};




int main(){
	Tree book;
	book.insert();
	book.display();
	
	
	
	return 0;
}
