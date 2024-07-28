# include<iostream>
using namespace std;

template<class T>
T* sel_sort(T arr[], int size){
    for (int i=0 ; i<size ; i++){
        int min = i;
        T temp;
        for (int j=i ; j<size ; j++){
            
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

    }
    return arr;
    
}


int main(){
    int arr[] = {1,5,3,2,6,8,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    sel_sort(arr, size);

    for (int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}