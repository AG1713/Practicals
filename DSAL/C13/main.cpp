#include <iostream>
#include <queue>
using namespace std;

class Queue{
	// Actually a circular queue
	int front;
	int rear;
	int *arr;
	int size;
	
	public:
	Queue(int n){
		size = n;
		arr = new int[n];
		front = -1;
		rear = -1;
	
	}
	
	bool is_empty(){
		if(front == -1)
			return true;
		return false;
	}
	
	bool is_full(){
		if((rear+1)%size == front)
			return true;
		return false;
	}
	
	int get_front(){
		return arr[front];
	}
	
	void q_push(int x){
		if(is_full()){
			return;
		}
		if(rear == -1){
			front++;
			rear++;
			arr[rear] = x;
			return;
		}
		rear = (rear+1)%size;
		arr[rear] = x;
		
	}
	
	void q_pop(){
		if(is_empty())
			return;
		if(front == rear){
			front = -1;
			rear = -1;
		}
		front = (front+1)%size;
	}
	
	
	
	
};

class Graph{
	int** ptr; // Variable size adjacency matrix
	int size;
	int *visited; // Array of visited elements
	
	
	// In this implementation, we assume the nods to be 0, 1, 2, 3, 4...  and so on.
	
	
	struct node{
		int value;
		node* next;
	};
	
	node **adjacency_list;
	
	
	
	public:
	Graph(int m){
		// m is taken as an input directly. m=size
		size = m;
		
		ptr = new int*[m];
		for (int i=0 ; i<m ; i++){
			ptr[i] = new int[m];
			
		}
		
		visited = new int[m];
		
		initialize_visited();
		
		
		// initializing adjacency list
		adjacency_list = new node*[size];
		for (int i=0 ; i<size ; i++){
			adjacency_list[i] = NULL;
		}
		
		
		
	}
	
	void initialize_visited(){
		
		for (int i=0 ; i<size ; i++){
			visited[i] = 0;
		}
	}
	
	
	void input(){
		int connection;
		
		cout<<"for values of connection only enter 1 or 0 accordingly"<<endl;
		for (int i=0 ; i<size ; i++){
			for (int j=0 ; j<size ; j++){
				
				cout<<"Does "<<i<<" have a connection with "<<j<<" : ";
				cin>>connection;
				ptr[i][j] = connection;
			
			}
		}
		
		
		for (int i=0 ; i<size ; i++){
			for (int j=0 ; j<size ; j++){
				cout<<ptr[i][j]<<" ";
			}
			cout<<endl;
		}
		
		
	}
	
	
	void initialize_adj_list(){
		node *temp;
		
		for (int i=0 ; i<size ; i++){
			for (int j=0 ; j<size ; j++){
				if(ptr[i][j] == 1){
					// The node is adjacent to it
					node *m = new node;
					m->value = j;
					m->next = NULL;
					
					if(adjacency_list[i] == NULL){
						adjacency_list[i] = m;
					}
					else{
						temp = adjacency_list[i];
						while(temp->next != NULL){
							temp = temp->next;
						}
						temp->next = m;
						
					}	
					
				}
				
			}
		}
		
		
	}
	
	void display_adj_list(){
		
		for (int i=0 ; i<size ; i++){
			node *temp = adjacency_list[i];
			cout<<"("<<i<<")";
			while(temp != NULL){
				cout<<"-->"<<temp->value;
				temp = temp->next;
			}
			cout<<endl;
			
			
		}
		
		
	}
	
	
	
	void DFS(int x){
		// Note that the elements are numbers 0, 1, 2, 3....
		int current = x;
		cout<<current<<" ";
		visited[current] = 1;
		
		for (int i=0 ; i<size ; i++){
			if((ptr[current][i] == 1) && (visited[i] == 0)){
				DFS(i);
			}
			
		}
	
	}
	
	
	
	
	void BFS(int x){
		queue<int> q;
		int current = x;
		
		initialize_visited();
		
		visited[current] = 1;
		
		
		q.push(current);
		
		while(!q.empty()){
			int temp = q.front();
			q.pop();
			cout<<temp<<" ";
			
			for (int i=0 ; i<size ; i++){
				if((ptr[temp][i] == 1) && (visited[i] == 0)){
					q.push(i);
					visited[i] = 1;
				}
				
			}
			
		}
		
	}
	
	
	void adj_DFS(int x){
		node *temp = adjacency_list[x];
		int current = x;
		cout<<current<<" ";
		visited[current] = 1;
		
		for (int i=0 ; i<size ; i++){
			while(temp != NULL){
				if(visited[temp->value] == 0){
					break;
				}
				temp = temp->next;
				
			}
			
			
			if(temp != NULL){
				adj_DFS(temp->value);
			}
			
		}
			
	}
	
	
	void adj_BFS(int x){
		queue<int> q;
		int current = x;
		
		initialize_visited();
		
		visited[current] = 1;
		
		
		q.push(current);
		
		while(!q.empty()){
			node* temp = adjacency_list[q.front()];
			cout<<q.front()<<" ";
			q.pop();
			
			for (int i=0 ; i<size ; i++){
				
				while(temp != NULL){
					if(visited[temp->value] == 0){
						break;
					}
					temp = temp->next;
				
				}
				
				if(temp != NULL){
					q.push(temp->value);
					visited[temp->value] = 1;
				}
				
			}
			
		}
	}
	
};




int main() {
	
	// Sample adjacency matrices
	// 4 - 0 1 1 0 1 0 1 1 1 1 0 1 0 1 1 0
	// 5 - 0 1 1 1 0 1 0 0 0 1 1 0 0 0 1 1 0 0 0 1 0 1 1 1 0
	// 7 - 0 1 1 0 0 0 0 1 0 0 1 0 0 0 1 0 0 0 1 1 0 0 1 0 0 0 0 1 0 0 1 0 0 0 1 0 0 1 0 0 0 1 0 0 0 1 1 1 0
	
	int vertex;
	cout<<"No. of vertices : ";
	cin>>vertex;
	
	Graph g(vertex);
	g.input();
	cout<<endl;
	cout<<"DFS : ";
	g.DFS(0);
	cout<<endl;
	cout<<"BFS : ";
	g.BFS(0);
	g.initialize_visited();
	cout<<endl;
	
	g.initialize_adj_list();
	cout<<"\n\nAdjacency List :- "<<endl;
	g.display_adj_list();
	
	cout<<endl;
	cout<<"Adjacency DFS : ";
	g.adj_DFS(0);
//	g.initialize_visited();
	cout<<endl;
	cout<<"Adjacency BFS : ";
	g.adj_BFS(0);
	
	
	return 0;
}

