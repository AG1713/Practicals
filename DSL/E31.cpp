// Question :-
// A double-ended queue (deque) is a linear list in which additions and deletions may be
// made at either end. Obtain a data representation mapping a deque into a one-
// dimensional array. Write C++ program to simulate deque with functions to add and
// delete elements from either end of the deque.

# include<iostream>
using namespace std;

// Linear Queue
template <class T>
class Queue{
    int f;
    int r;
    int* arr;
    int size;

    public:
    Queue(int s){
        f = -1;
        r = -1;
        size = s;
        arr = new int[size];
    }

    // All queue state functions
    int q_if_full(){
        if((f==0)&&(r==(size-1))){
            return 1;
        }
        return 0;
    }
    int q_if_emt(){
        if((f==-1)||(f>r)){
            return 1;
        }
        return 0;
    }
    int r_max_reached(){
        if(r==size-1){
            return 1;
        }
        return 0;
    }
    int f_min_reached(){
        if(f==0){
            return 1;
        }
        return 0;
    }

    // All Queue operatino functions
    void q_fInsert(T ele){
        if(q_if_full()!=1){
            if(f_min_reached()!=0){
                if(f==-1){
                    f++;
                    r++;
                    arr[f] = ele;
                }
                else{
                    f--;
                    arr[f] = ele;
                }
            }
            else{
                cout<<"f min index reached"<<endl;
            }
        }
        else{
            // Message here
            cout<<"Queue full"<<endl;
            return;
        }
    }
    

    void q_rInsert(T ele){
        if(q_if_full()!=1){
            if(r_max_reached()!=1){
                if(f==-1){
                    f++;
                    r++;
                    arr[r] = ele;
                }
                else{
                    r++;
                    arr[r] = ele;
                }
            }
            else{
                cout<<"r max index reached"<<endl;
            }
        }
        else{
            // Message here
            cout<<"Queue full"<<endl;
            return;
        }
    }

    void q_fDelete(){
        if(q_if_emt()!=1){
            f++;
        }
        else{
            // Message here
            cout<<"Queue empty"<<endl;
            return;
        }
    }

    void q_rDelete(){
        if(q_if_emt()!=1){
            r--;
        }
        else{
            // Message here
            cout<<"Queue empty"<<endl;
            return;
        }
    }

    void q_display(){
        if(f==-1){
            return;
        }
        cout<<"Queue : {";
        for (int i=f ; i<=r ; i++){
            cout<<arr[i]<<' ';
        }
        cout<<"}"<<endl;
    }

};

int main(){
    Queue<int> q(4);
    int element;
    int choice;

    cout<<"Dequeue program started..."<<endl;
    while(choice!=6){
        cout<<"\n\nOperations :-"<<endl;
        cout<<"1. Insert an element from front"<<endl;
        cout<<"2. Insert an element from rear"<<endl;
        cout<<"3. Remove an element from front"<<endl;
        cout<<"4. Remove an element from back"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your operation number :";
        cin>>choice;


        // We can add more conditions in cases, for eg. if you choose 1 but the minimum index of f is reached,
        // we can display it before we enter the value of element. However this would make program look complicated
        switch(choice){
            case 1:{
                cout<<"You chose insert from front"<<endl;
                cout<<"Enter the value of the element :";
                cin>>element;
                q.q_fInsert(element);
                break;
            }
            case 2:{
                cout<<"You chose insert from rear"<<endl;
                cout<<"Enter the value of the element :";
                cin>>element;
                q.q_rInsert(element);
                break;
            }
            case 3:{
                cout<<"You chose remove from front"<<endl;
                q.q_fDelete();
                break;
            }
            case 4:{
                cout<<"You chose delete from rear"<<endl;
                q.q_rDelete();
                break;
            }
            case 5:{
                cout<<"You chose to display your queue"<<endl;
                q.q_display();
                break;
            }
            case 6:{
                cout<<"Exiting..."<<endl;
                break;
            }
            default:{
                cout<<"Invalid choice!"<<endl;
            }
        }

    }



    return 0;
}