# include<iostream>
using namespace std;

// insert
// delete
// size
// get head
// get end

class Linked_list{
    struct node{
        int value;
        node* next;
    };
    node *HEAD;
    int count;
    node *end;

    public:
    Linked_list(){
        HEAD = NULL;
        end = NULL;
    }
    void l_insert_end(int val){
        node* m = new node;
        m->value = val;
        m->next = NULL;

        node* temp = HEAD; // Traversing node

        if(HEAD == NULL){
            HEAD = m;
            end = m;
        }
        else{
            // I also could have done end->next  = m, and then end = m
            while((temp->next)!=NULL){
                temp = temp->next;
            }
            // We come out with temp as last node
            temp->next = m;
        }
    }

    void l_insert_front(int val){
        node* m = new node;
        m->value = val;
        m->next = HEAD;
        HEAD = m;
    }

    void l_delete_end(){
        node *temp = HEAD;
        node *prev = NULL;

        while((temp->next)!=NULL){
            prev = temp;
            temp = temp->next;
        }
        // Now temp is last index

        if(prev == NULL){
            HEAD = NULL;
            delete temp;
        }
        else{
            prev->next = temp->next;
            delete temp;
        }

    }

    void l_delete_front(){
        if(HEAD == NULL){
            return;
        }
        node *temp = HEAD;
        HEAD = HEAD->next;
        delete temp;
    }

    void display(){
        if(HEAD==NULL){
            cout<<"List empty"<<endl;
            return;
        }
        node* temp = HEAD;
        while(temp!=NULL){
            cout<<(temp->value)<<" ";
            temp = temp->next;
        }
        cout<<endl;

    }


};


int main(){
    Linked_list l1;
    l1.display();
    cout<<"This"<<endl;
    l1.l_insert_end(12);
    l1.display();
    l1.l_insert_front(6);
    l1.display();
    l1.l_delete_end();
    l1.display();


    
    return 0;
}