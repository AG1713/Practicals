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
            // Message here
            cout<<"Queue full"<<endl;
            return;
        }
    }

    void q_delete(){
        if(q_if_emt()!=1){
            f++;
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
    Queue<int> q(3);
    q.q_display();
    q.q_delete();
    q.q_insert(4);
    q.q_display();
    q.q_insert(5);
    q.q_insert(1);
    q.q_display();
    q.q_insert(6);
    q.q_insert(4);
    q.q_delete();
    q.q_delete();
    q.q_display();
    q.q_delete();
    q.q_display();
    q.q_delete();



    
    return 0;
}