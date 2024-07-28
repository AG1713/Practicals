#include <iostream>
using namespace std;


class Set{
	int *arr_set;
	int size;

	public:
	Set(){
		arr_set = NULL;
		size = 0;
	}
	
	Set(Set &b){
		size = b.getSize();
		arr_set = new int[size];
		int *arr_setb = b.getSet();
		
		
		for (int i=0 ; i<size ; i++){
			arr_set[i] = arr_setb[i];
		}
		
	}
	
	void display(){
		for (int i=0 ; i<size ; i++){
			cout<<arr_set[i]<<" ";
		}
		cout<<endl;
	}
	
	
	void add(int x){
		// Check if already exists
		if (contains(x)){
			return;
		}
		
		// Get a position to insert the value
		int position = 0;
		while(position < size){
			if (arr_set[position] > x){
				break;
			}
			position++;
		}
		// The above can be also done using binary search
		
		
		// Create a new dynamic array
		int *temp = new int[size+1];
		
		// Insert the elements from the old array to the new
		for (int i=0 ; i<position ; i++){
			temp[i] = arr_set[i];
		}
		temp[position] = x;
		for (int i=position+1 ; i<size+1 ; i++){
			temp[i] = arr_set[i-1];
		}
		
		// Delete the exisiting pointer and replace it with new one
		delete[] arr_set;
		arr_set = temp;
		size = size+1;
	}
	
	
	void remove(int x){
		
		// Finding the index
		int position = -1;
		for (int i=0 ; i<size ; i++){
			if (arr_set[i] == x){
				position = i;
				break;
			}
		}
		if (position == -1){
			return;
		}
		// We can also use binary search here
		
		
		
		// Shifting the values after the deleted element (We are deleting logically by replacement
		// of the element at index 'position'
		for (int i=position ; i<size-1 ; i++){
			arr_set[i] = arr_set[i+1];
		}
		
		// Actual deletion
		delete &arr_set[size-1];
		// Deleting the last element since we have already logically deleted the
		// element which we needed to delete, now we are just removing the excess coppy of the last element
		
		size--;
	}
	
	
	bool contains(int x){
		// returns an index
		int s = 0;
		int e = size-1;
		
		// Binary search
		while(s<=e){
			int mid = s + (e-s)/2;
			
			if (arr_set[mid] == x){
				return true;
			}
			else if(arr_set[mid] < x){
				s = mid+1;
			}
			else{
				e = mid-1;
			}
		}
		return false;
	}
	
	
	int getSize(){
		return size;
	}

	// Iterator part here
	// Iterator to loop over collection
    class Iterator {
    private:
        int *ptr;

    public:
        Iterator(int *p) : ptr(p) {}

        // Pre-increment operator
        Iterator &operator++() {
            ++ptr;
            return *this;
        }

        // Dereference operator
        int &operator*() const {
            return *ptr;
        }

        // Not equal operator
        bool operator!=(const Iterator &other) const {
            return ptr != other.ptr;
        }
    };

    // Begin iterator
    Iterator begin() const {
        return Iterator(arr_set);
    }

    // End iterator
    Iterator end() const {
        return Iterator(arr_set + size);
    }
	
	
	private:
	int* getSet(){
		return arr_set;
	}
	
	public:
	Set set_intersection(Set &b){
		int* arr_setb = b.getSet();
		int sizeb = b.getSize();
		
		Set c;
		
		int i = 0;
		int j = 0;
		
		while((i<size) && (j<sizeb)){
			if (arr_set[i] == arr_setb[j]){
				c.add(arr_set[i]);
				i++;
				j++;
			}
			else if (arr_set[i] < arr_setb[j]) i++;
			else j++;
		}
		// There could be easier method than this, but this one seems fastest
		
		
		return c;
	}
	
	Set set_union(Set &b){
		Set c;
		
		int* arr_setb = b.getSet();
		int sizeb = b.getSize();
		
		int i = 0;
		int j = 0;
		
		while((i<size) && (j<sizeb)){
			if (arr_set[i] == arr_setb[j]){
				c.add(arr_set[i]);
				i++;
				j++;
			}
			else if (arr_set[i] < arr_setb[j]){
				c.add(arr_set[i]);
				i++;
			}
			else{
				c.add(arr_setb[j]);
				j++;
			}
		}
		while(i<size){
			c.add(arr_set[i++]);
		}
		while(j<sizeb){
			c.add(arr_setb[j++]);
		}
		
		
		return c;
	}
	
	Set difference(Set &b){
		Set c = *this;
		int* arr_setb = b.getSet();
		int sizeb = b.getSize();
		
		
		for (int i=0 ; i<sizeb ; i++){
			c.remove(arr_setb[i]);
		}
		
		return c;
	}
	
	bool isSubset(Set &b){
		for (int i=0 ; i<size ; i++){
			if (!b.contains(arr_set[i])){
				return false;
			}
		}
		return true;
	}
	
	
};



int main() {

	Set s1;
	s1.add(3);
	s1.add(4);
	s1.add(5);
	s1.add(6);
	
	Set s2;
	s2.add(5);
	s2.add(6);
	s2.add(7);
	
	cout<<"s1 : ";
	s1.display();
	cout<<"s2 : ";
	s2.display();
	
	cout<<"Answer : "<<endl;
	cout<<"Intersection : ";
	s1.set_intersection(s2).display();
	cout<<"Union : ";
	s1.set_union(s2).display();
	cout<<"Difference : ";
	s1.difference(s2).display();
	
	
	// Making s1 subset of s2
	s1.remove(3);
	s1.remove(4);
	s1.display();
	cout<<"Removed 3, 4 from s1"<<endl;
	cout<<"Subset : "<<s1.isSubset(s2)<<endl;
	
	// Iterator
	Set::Iterator itr = s1.begin();
	cout<<"Iterator value : "<<*itr<<endl;
	
	
	return 0;
}
