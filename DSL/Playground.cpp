# include<iostream>
using namespace std;

class Linked_list{
    struct node{
        int value;
        node *next;
    };

    node *HEAD;
    node *end;
    int size;

    Linked_list(){
        HEAD = NULL;
        end = NULL;
    }
    void l_insert_end(int val){
        node *m = new node;
        m->value = val;
        m->next = NULL;

        if(HEAD==NULL){
            HEAD = m;
            end = HEAD;
        }
        else{
            node *temp = HEAD;

            while((temp->next)!=NULL){
                temp = temp->next;
            }
            // Exiting with last node as temp
            temp->next = m;
        }
    }
    void l_insert_front(int val){
        node *m = new node;
        m->value = val;
        m->next = HEAD;
        HEAD = m;
    }

    void l_delete_end(){
        node* prev = NULL;
        node* current = HEAD;

        // Case 1: If linked list is empty
        if(current == NULL){
            return;
        }
        // Case 2: If linked list has only one node
        // Case 3: Many nodes

        while((current->next)!=NULL){
            current = current->next;
            prev = current;
        }
        // current is last node now
        
        if(prev==NULL){// i.e if Linked list has only one node
            HEAD = NULL; //Which is NULL ofc coz its first node
            delete current;
        }
        else{
            cout<<"That"<<endl;
            prev->next = NULL; // Which is NULL again ofc
            delete current;
        }
    }



};



int main(){
    
    return 0;
}