// Question :-
// Department of Computer Engineering has student's club named 'Pinnacle Club'. Students
// of second, third and final year of department can be granted membership on request.
// Similarly one may cancel the membership of club. First node is reserved for president of
// club and last node is reserved for secretary of club. Write C++ program to maintain club
// member‘s information using singly linked list. Store student PRN and Name. Write
// functions to:
// a) Add and delete the members as well as president or even secretary.
// b) Compute total number of members of club
// c) Display members
// d) Two linked lists exists for two divisions. Concatenate two lists.

# include<iostream>
using namespace std;

class Club{
	struct node{ // Structure of each node in a linked list. Can be edited, but make sure to replace the variable names
		int PRN;
        string name;
		node *next;
	};
	
	int size; // Stores the size of the linked list, instead of making a function and counting every element
	
	public:
	node* HEAD; // Pointer to the first node of the linked list
    node* secr;

	Club(){
		HEAD = NULL;
		secr = NULL;
		size = 0;
	}

	void l_insert(int p, string n, int index){
    	node* m = new node;
		if(size==0){ // If linked list is empty
			m->PRN = p;
            m->name = n;
			m->next = NULL;
			HEAD = m;
            secr = HEAD;
			size++;
			return;
		}

    	node* prev = NULL; // This is the node which is just one index behind the index
		// we ned to insert PRN to. We would soon give it its PRN
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
    	m->PRN = p;
        m->name = n;
        if(i==size){secr = m;}
        if(prev==NULL){ // If element added at first index
			m->next = HEAD;
			HEAD = m;
			return;
		}
    	m->next = prev->next;
    	prev->next = m;
		size++;
		cout<<(secr->next)<<endl;
	}
	
	void l_delete(int p){
		node* temp = HEAD; // Traversing node
		node* prev = NULL; // One node behind traversing node

        if(temp==NULL){ // If linked list is empty
            cout<<"Linked list is empty"<<endl;
            return;
        }

		while((temp!=NULL)&&(temp->PRN != p)){ // Traversing to the element containing the PRN
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
            delete temp;
        }

	}
	
	int l_size(){ // It does nothing lol
		return size;
	}
	
	void l_display_members(){ // Made int so that it returns a value and doesn't get out of super function
        cout<<"\n\n----------------------------------------------------------------------------"<<endl;
        if(size==0){ // If no members
            cout<<"None";
            return;
        }

		node* temp = HEAD;
        cout<<"President :-\n"<<"Name :-"<<HEAD->name<<"\nPRN:-"<<HEAD->PRN<<endl;
        cout<<"\nSecratory :-\n"<<"Name :-"<<secr->name<<"\nPRN:-"<<secr->PRN<<endl;
        	
		if(size>2){temp = temp->next;}

		cout<<"\nMembers - "<<endl;
		cout<<"Name\t\t"<<"PRN"<<endl;
		while((size>2)&&(temp!=secr)){
			cout<<(temp->name)<<"\t\t"<<(temp->PRN)<<endl;
			temp = temp->next;
		}
        cout<<"----------------------------------------------------------------------------"<<endl;
	}

	node* get_president(){
		return HEAD;
	}
	node* get_secretary(){
		return secr;
	}

};



void menu(Club *c1){
	int choice;
    int ind;
    string n;
    int p;

	while(choice!=7){
		cout<<"\n\nOperations -"<<endl;
		cout<<"1. Add a member"<<endl;
		cout<<"2. Add new president"<<endl;
		cout<<"3. Add new Secretary"<<endl;
		cout<<"4. Remove a member"<<endl;
		cout<<"5. Get strength of the club"<<endl;
		cout<<"6. Display the club"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"Choice :";
		cin>>choice;

		switch (choice)
		{
		case 1:
			cout<<"Enter the PRN of the member :";
			cin>>p;
			cout<<"Enter the name of the member :";
			cin>>n;
			c1->l_insert(p, n, c1->l_size());
			break;
		case 2:
			cout<<"Enter the PRN of the President :";
			cin>>p;
			cout<<"Enter the name of the President :";
			cin>>n;
			c1->l_insert(p, n, 0);
			break;
		case 3:
			cout<<"Enter the PRN of the Secretary :";
			cin>>p;
			cout<<"Enter the name of the Secretary :";
			cin>>n;
			c1->l_insert(p, n, c1->l_size());
			break;
		case 4:
			cout<<"Enter the PRN of member to be deleted :";
			cin>>p;
			c1->l_delete(p);
			break;
		case 5:
			cout<<c1->l_size()<<endl;
			break;
		case 6:
			c1->l_display_members();
			break;
		case 7:
			cout<<"Exiting..."<<endl;
			break;
		
		default:
			cout<<"Invalid Choice"<<endl;
			break;
		}
	}

}

void concatenate(Club &c, Club b){
	(c.secr)->next = (b.HEAD);
	c.secr = b.secr;
}


int main(){
	int choice;

    Club Div_A;
	Club Div_B;
	Club Div_AB;

	// menu(&Div_A);


	cout<<"Starting..."<<endl;
	while(choice!=4){
		cout<<"\n\nDivisions -"<<endl;
		cout<<"1. A"<<endl;
		cout<<"2. B"<<endl;
		cout<<"3. A and B concatinated"<<endl;
		cout<<"4. Exit whole program"<<endl;
		cout<<"Enter the division :"<<endl;
		cin>>choice;

		switch(choice){
			case 1:{
				cout<<"Entering Pinnacle club of Division A..."<<endl;
				menu(&Div_A);
				break;
			}
			case 2:{
				cout<<"Entering Pinnacle club of Division B..."<<endl;
				menu(&Div_B);
				break;
			}
			case 3:{
				if((Div_A.HEAD != NULL)&&(Div_B.HEAD != NULL)){
					Club Div_AB(Div_A);
					cout<<"Concatenating Divisions A and B..."<<endl;
					concatenate(Div_AB, Div_B);

					cout<<"Entering concatinated club..."<<endl;
					menu(&Div_AB);

					break;
				}
				else{
					cout<<"Both divisions must have atleast one member"<<endl;
					break;
				}
			}
			case 4:{
				cout<<"Exiting the whole program..."<<endl;
				break;
			}
			default:{
				cout<<"Invalid choice"<<endl;
				break;
			}
		}

	}

    return 0;
}
