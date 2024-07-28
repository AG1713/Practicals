// Question :-
// A palindrome is a string of character that‘s the same forward and backward. Typically,
// punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop”
// is a palindrome, as can be seen by examining the characters “poor danisina
// droop” and observing that they are the same forward and backward. One way to check
// for a palindrome is to reverse the characters in the string and then compare with them
// the original-in a palindrome, the sequence will be identical. Write C++ program with

// functions-
// a) To remove spaces of a string
// b) To check whether given string is palindrome or not

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


template<class T>
class Stack{
	T* arr;
	int top;
	int size;
	
	
	public:
		Stack(int s){
			size = s;
// 			cout<<size<<endl;
			arr = new T[size];
			top = -1;
		}

        T peek(){
            return arr[top];
        }
		
		int if_full(){
			if(top==(size-1)){
				return 1;
			}
			return 0;
		}
		
		int if_emt(){
			if(top==-1){
				return 1;
			}
			return 0;
		}
		
		void q_push(T in){
			if( !(if_full()) ){
				top = top+1;
				arr[top] = in;
			}
			else {
				cout<<"The stack is full, cannot add more elements"<<endl;
			}
		}
		
		void q_pop(){
			if( !(if_emt()) ){
				top = top-1;
			}
			else {
				cout<<"The stack is empty, cannot delete more elements"<<endl;
			}
		}
		
		void display(){
			cout<<"Stack : {";
			for (int i=0 ; i<=top ; i++){
			    if (i == top){
			        cout<<arr[i];
			        break;
			    }
			    cout<<arr[i]<<", ";
			}
			cout<<"}"<<endl;
		}
};

string rem_space_punctuation_capitals(string s){
    string result;

    for(int i=0 ; i<s.size() ; i++){
        if(((s[i]<65)||(s[i]>122))||((s[i]>90)&&(s[i]<97))){ // Eliminates all characters except alphabets
            continue;
        }
        if((s[i]>=65)&&(s[i]<=90)){// If capital letters
            result = result + char(s[i]+32); // When we add a char and an int in c++, it is converted to int
            // Therefore it is neccessary to convert it back to char type
            continue;
        }
        result = result + s[i];
    }
    return result;

}

void Palindrome_check(string s1){
	string s2;
	
	Stack<char> pal_stk(s1.length());
	
	
	// Inserting string into stack
	for (int i=0 ; i<s1.length() ; i++){
		pal_stk.q_push(s1[i]);
	}
	
	// Getting a string from stack
	for (int i=0 ; i<s1.length() ; i++){
		s2 = s2+pal_stk.peek(); // Strings are immuatable in C++ but we can concatenate them. Its weird but it works!
        pal_stk.q_pop();
	}
	
	if(s1==s2){
		cout<<"The string is a palindrome"<<endl;
	}
	else{
		cout<<"The string is not a palindrome"<<endl;
	}
}


int main(){
	string s1, s2;
	cout<<"Enter the string :-";
	getline(cin, s1); // String module function to get whole line in a string, thus ignoring spaces
    // NOTE:-
    // If you are using char[] instead of string, the above may not work
    // in such case, take input as :- scanf("%[^\n]",<string_name>);
    // afeter that, you may print the string normally

    s2 = rem_space_punctuation_capitals(s1);
	Palindrome_check(s2);
	
	return 0;
}

