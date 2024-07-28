#include <iostream>
#include <fstream>
using namespace std;

struct index{
	int id;
	streampos position;
};


struct employee{
		int id;
		char name[50];
		char designation[50];
		int salary;
	};

class File{
	public:
	streampos lastindex;
	
	File(){
		lastindex = 0;
	}
	
	
	
	
	
	void add_employee(){
		index i;
		employee e;
		
		fstream index_file;
		fstream employee_file;
		
		cout<<"Enter details of the employee : "<<endl;
		cout<<"ID : ";
		cin>>e.id;
		cout<<"Name : ";
		cin>>e.name;
		cout<<"Designation : ";
		cin>>e.designation;
		cout<<"Salary : ";
		cin>>e.salary;
		
		i.id = e.id;
		
		// INPUT PART ENDS
		
		// Putting in EmployeeDB.dat
		employee_file.open("EmployeeDB.dat", ios::app | ios::binary); // IDk if this 2 modes are compatible with each other
		i.position = lastindex;
		lastindex = lastindex + sizeof(e);
		employee_file.write((char *)(&e), sizeof(e));
		employee_file.close();
		
		// Putting in Index.dat
		index_file.open("Index.dat", ios::app | ios::binary); // IDk if this 2 modes are compatible with each other
		index_file.write((char *) (&i), sizeof(i));
		index_file.close();
		
		
	}
	
	
	void retrieve(){
		int id;
		cout<<"Enter ID : ";
		cin>>id;
		
		fstream index_file;
		fstream employee_file;
		index_file.open("Index.dat", ios::in);
		
		index i; // Sample index
		while(index_file.read((char *)(&i), sizeof(i))){
//			cout<<i.id<<endl;
//			cout<<(i.id == id)<<endl;
			if (i.id == id){
				employee_file.open("EmployeeDB.dat", ios::in | ios::binary);
				employee e;
				employee_file.seekg(i.position, ios::beg);
				employee_file.read((char *)(&e), sizeof(e));
				employee_file.close();
				
				cout<<"ID : "<<e.id<<endl;
				cout<<"Name : "<<e.name<<endl;
				cout<<"Designation : "<<e.designation<<endl;
				cout<<"Salary : "<<e.salary<<endl;
				return;
			}
				
		}
		cout<<"Not found"<<endl;
	}
	
	void display(){
		fstream index_file;
		fstream employee_file;
		
		index i;
		employee e;
		
		cout<<"Index file..."<<endl;
		
		index_file.open("Index.dat", ios::in);
		while(index_file.read((char *)(&i), sizeof(i))){
			cout<<"ID : "<<i.id<<endl;
			cout<<"Position : "<<i.position<<endl;
		}
		cout<<endl;
		
		cout<<"Employee file"<<endl;
		employee_file.open("EmployeeDB.dat", ios::in|ios::binary);
		while(employee_file.read((char *)(&e), sizeof(e))){
			cout<<"ID : "<<e.id<<endl;
			cout<<"Name : "<<e.name<<endl;
			cout<<"Designation : "<<e.designation<<endl;
			cout<<"Salary : "<<e.salary<<endl;
			cout<<endl;
		}
		cout<<endl;
		
		
	}
	
	
};




int main(){
	
	File f;
//	f.add_employee();
//	f.add_employee();
//	f.retrieve();
//	f.retrieve();
//	f.display();
	
	
	
	
	return 0;
}


