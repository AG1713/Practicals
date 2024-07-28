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
    Queue<int> q(2);
    q.q_fDelete();
    q.q_rDelete();
    q.q_fInsert(2);
    q.q_fDelete();
    q.q_display();
    q.q_rInsert(8);
    q.q_display();

    return 0;
}