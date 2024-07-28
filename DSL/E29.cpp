// Question :-
// Queues are frequently used in computer programming, and a typical example is the
// creation of a job queue by an operating system. If the operating system does not use
// priorities, then the jobs are processed in the order they enter the system. Write C++
// program for simulating job queue. Write functions to add job and delete job from queue.

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

    int q_if_full(){
        if(r==(size-1)){
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

    void q_insert(T ele){
        if(q_if_full()!=1){
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
            cout<<"No more recruiting!"<<endl;
            return;
        }
    }

    void q_delete(){
        if(q_if_emt()!=1){
            f++;
        }
        else{
            cout<<"No more active employees"<<endl;
            return;
        }
    }

    void q_display(){
        if(f==-1){
            return;
        }
        cout<<"IDs : {";
        for (int i=f ; i<=r ; i++){
            cout<<arr[i]<<' ';
        }
        cout<<"}"<<endl;
    }

};

int main(){
    Queue<int> q(4);
    int id;
    int choice;

    cout<<"Dequeue program started..."<<endl;
    while(choice!=6){
        cout<<"\n\nOperations :-"<<endl;
        cout<<"1. Add an employee"<<endl;
        cout<<"2. Remove an employee"<<endl;
        cout<<"3. Check if there are no employees"<<endl;
        cout<<"4. Check if still recruiting (Queue is full or not)"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your operation number :";
        cin>>choice;


        // We can add more conditions in cases, for eg. if you choose 1 but queue is full,
        // we can display it before we enter the value of id. However this would make program look complicated to look
        switch(choice){
            case 1:{
                cout<<"You chose to add an employee"<<endl;
                cout<<"Enter the value of the id :";
                cin>>id;
                q.q_insert(id);
                break;
            }
            case 2:{
                cout<<"You chose to remove an employee"<<endl;
                q.q_delete();
                break;
            }
            case 3:{
                cout<<"You chose to check if there are no employees"<<endl;
                if(q.q_if_emt()){
                    cout<<"There are no employees"<<endl;
                    break;
                }
                cout<<"There are active employees"<<endl;
                break;
            }
            case 4:{
                cout<<"You chose to check if still recruiting"<<endl;
                if(q.q_if_full()){
                    cout<<"No more recruiting!"<<endl;
                    break;
                };
                cout<<"Still recruiting more"<<endl;
                break;
            }
            case 5:{
                cout<<"You chose to display ids of employees"<<endl;
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