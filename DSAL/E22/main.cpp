#include <iostream>
using namespace std;


class Heap{
	int heap[30];
	
	public:
	Heap(){
		// Note that first index denotes elements in the heap
		heap[0] = 0;
	}
	
	
	void add(int x){
		heap[0]++;
		heap[heap[0]] = x;
		
		int index = heap[0];
		
		while (index > 1){
			int parent = index/2;
			
			if (heap[parent] < heap[index]){
				swap(heap[parent], heap[index]);
				index = parent;
			}
			else{
				return;
			}
			
		}
		
	}
	
	
	void heapify(int arr[], int size, int i){
		// size = no. of elements +1
		int largest = i;
		int left = i*2;
		int right = (i*2)+1;
		
		if (left <= size && arr[largest] < arr[left]){
			largest = left;
		}
		if (right <= size && arr[largest] < arr[right]){
			largest = right;
		}
		// We didn't swap in the if conditions since we need to make sure
		// that the largest is the greatest value among the indexes i, left and right
		
		if (largest != i){
			swap(arr[largest], arr[i]);
			heapify(arr, size, largest);
		}
		
		
	}
	
	
	void heapsort(int arr[], int n){
		int size = n-1;
		
		while(size>1){
			// swap
			swap(arr[1], arr[size]);
			
			size--;
			
			heapify(arr, size, 1);
		}
		
	}
	
		
	
	void print(){
		for (int i=1 ; i<=heap[0] ; i++){
			cout<<heap[i]<<" ";
		}
		cout<<endl;
	}
	
	
};






int main(){
	Heap h;
	h.add(50);
	h.add(55);
	h.add(53);
	h.add(52);
	h.add(54);
	
	h.print();
	
	
	int arr[6] = {-1, 54,53,55,52,50};
	int size = 6;
	
	for (int i=size/2 ; i>0 ; i--){
		h.heapify(arr, size, i);
	}
	cout<<"Printing"<<endl;
	
	for (int i=1 ; i<size ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	cout<<"Printing sorted array"<<endl;
	
	h.heapsort(arr, size);
	for (int i=1 ; i<size ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
