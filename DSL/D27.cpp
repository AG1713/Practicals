// Question :-
// Implement C++ program for expression conversion as infix to postfix and its evaluation
// using stack based on given conditions:
// 1. Operands and operator, both must be single character.
// 2. Input Postfix expression must be in a desired format.
// 3. Only '+', '-', '*' and '/ ' operators are expected.

# include<iostream>
using namespace std;


template<class T>
class Stack{
	T* arr;
	int top;
	int size; // Total maximum size of stack
	
	
	public:
		Stack(int s){
			size = s;
// 			cout<<size<<endl;
			arr = new T[size];
			top = -1;
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
				cout<<"Deleting element :"<<arr[top]<<endl;
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
        
        T get_top_ele(){
            return arr[top];
        }

        T get_top(){
            return top;
        }
};

int get_precedence(char x){
    if(x=='^'){
        return 3;
    }
    else if((x=='*')||(x=='/')){
        return 2;
    }
    else if((x=='+')||(x=='-')){
        return 1;
    }
    else{
        return -1;
    }
}


string conversion(string infix_exp){
    Stack<char> converter_stk(10);
    string postfix_exp = "";
    converter_stk.display();

    // Conversion process begins
    for (int i=0 ; i<infix_exp.length() ; i++){
        if((infix_exp[i]=='*')||(infix_exp[i]=='/')||(infix_exp[i]=='+')||(infix_exp[i]=='-')){          
            while(get_precedence(converter_stk.get_top_ele())>=get_precedence(infix_exp[i])){
                // Poppping only those which are at same precedence level
                postfix_exp += converter_stk.get_top_ele();
                converter_stk.q_pop();
            }
            // Atlast pushing lastest operands
            converter_stk.q_push(infix_exp[i]);
        }
        else if(infix_exp[i]=='('){
            // Just adding, its to detect when a bracket expression starts
            converter_stk.q_push(infix_exp[i]);
        }
        else if(infix_exp[i]==')'){
            while(converter_stk.get_top_ele()!='('){
                // We add all operators until we get '(' as top element
                postfix_exp += converter_stk.get_top_ele();
                converter_stk.q_pop();
            }
            converter_stk.q_pop();
        }
        else{
            postfix_exp += infix_exp[i];
        }
    
    }
    while(converter_stk.get_top()>=0){
        // After for loop ends, end of expression is reached and thus we add remaining elements
        postfix_exp += converter_stk.get_top_ele();
        converter_stk.q_pop();
    }
    return postfix_exp;
    // Conversion process ends
}

int evaluation(string postfix_exp){
    Stack<int> eval_stk(postfix_exp.length());

    for (int i=0 ; i<postfix_exp.length() ; i++){
        if((postfix_exp[i]>='0')&&(postfix_exp[i]<='9')){
            eval_stk.q_push(postfix_exp[i]-'0');
        }
        else{
            int op2 = eval_stk.get_top_ele();
            eval_stk.q_pop();
            int op1 = eval_stk.get_top_ele();
            eval_stk.q_pop();

            if(postfix_exp[i]=='+'){
                eval_stk.q_push(op1+op2);
            }
            else if(postfix_exp[i]=='-'){
                eval_stk.q_push(op1-op2);
            }
            else if(postfix_exp[i]=='/'){
                eval_stk.q_push(op1/op2);
            }
            else if(postfix_exp[i]=='*'){
                eval_stk.q_push(op1*op2);
            }
        }
    }
    return eval_stk.get_top_ele();

}

int main(){
    string infix_exp = "(a+b*c)/(x+y/z)";
    string postfix_exp = conversion(infix_exp);
    cout<<postfix_exp<<endl;
    cout<<"--------------------------------------------------"<<endl;
    // cout<<evaluation(postfix_exp)<<endl;


    
    return 0;
}