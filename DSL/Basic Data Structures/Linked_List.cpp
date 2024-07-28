#include <iostream>
using namespace std;

template<class T>
class Linked_list{
	struct node{ // Structure of each node in a linked list. Can be edited, but make sure to replace the variable names
		T value;
		node *next;
	};
	node* HEAD; // Pointer to the first node of the linked list
	int size; // Stores the size of the linked list, instead of making a function and counting every element
	
	public:
	Linked_list(){
		HEAD = NULL;
		size = 0;
	}

	void l_insert(int value, int index){
    	node* m = new node;
		if(size==0){ // If linked list is empty
			m->value = value;
			m->next = NULL;
			HEAD = m;
			size++;
			return;
		}

    	node* prev = NULL; // This is the node which is just one index behind the index
		// we ned to insert value to. We would soon give it its value
    	int i=0;

    	while(i<index){
    	    if(i>(size-1)){
    	        cout<<"Index too big, adding said element to the last index."<<endl;
    	        break;
    	    }
    	    if(prev == NULL){ // This is neccessary for first iteration of while loop here
    	        prev = HEAD;
    	        i++;
    	        continue;
    	    }
    	    i++;
    	    prev = prev->next;
    	}
    	m->value = value;
		if(prev==NULL){ // If element added at first index
			m->next = HEAD;
			HEAD = m;
			return;
		}
    	m->next = prev->next;
    	prev->next = m;
		size++;
	}
	
	void l_delete(T val){
		node* temp = HEAD; // Traversing node
		node* prev = NULL; // One node behind traversing node

        if(temp==NULL){ // If linked list is empty
            cout<<"Linked list is empty"<<endl;
            return;
        }

		while((temp!=NULL)&&(temp->value != val)){ // Traversing to the element containing the value
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL){ // If not found
            cout<<"Node not found"<<endl;
        }
		else if(prev==NULL){// i.e. if first node is to be deleted
			size--;
			HEAD = temp->next;
			delete temp;
		}
        else{ // Normal way
			size--;
            prev->next = temp->next;
			cout<<"Here"<<endl;
            delete temp;
        }

	}
	
	int l_size(){ // It does nothing lol
		return size;
	}
	
	void l_display_members(){
		node* temp = HEAD;
		cout<<"Members - ";
		
		while(temp!=NULL){
			cout<<(temp->value)<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
};

int main(){
	int choice=0;
	int val;
	int ind;
	Linked_list<int> list1;

	while(choice!=6){
		cout<<"\n\nOperations -"<<endl;
		cout<<"1. Insert a node"<<endl;
		cout<<"2. Insert at a index"<<endl;
		cout<<"3. Delete a node"<<endl;
		cout<<"4. Get length of the linked list"<<endl;
		cout<<"5. Display the linked list"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Choice :";
		cin>>choice;

		switch (choice)
		{
		case 1:
			cout<<"Enter the value to be entered :";
			cin>>val;
			list1.l_insert(val, list1.l_size());
			break;
		case 2:
			cout<<"Enter the value to be entered :";
			cin>>val;
			cout<<"Enter the value of index :";
			cin>>ind;
			list1.l_insert(val, ind);
			break;
		case 3:
			cout<<"Enter the value to be deleted :";
			cin>>val;
			list1.l_delete(val);
			break;
		case 4:
			cout<<list1.l_size()<<endl;
			break;
		case 5:
			list1.l_display_members();
			break;
		case 6:
			cout<<"Exiting..."<<endl;
			break;
		
		default:
			cout<<"Invalid Choice"<<endl;
			break;
		}
	}

	return 0;
}
