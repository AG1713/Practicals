#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Student{
	public:
		
	int rollno;
	string name;
	char division;
	string address;

	
	Student(){
		rollno = 0;
		name = "";
		division = 'A';
		address = "";
	}
	
	Student(int r, string n, char d, string a){
		rollno = r;
		name = n;
		division = d;
		address = a;
	}
	
	void getdata(){
		cout<<"-----Student-----"<<endl;
		cout<<"Roll no. : "<<rollno<<endl;
		cout<<"Name : "<<name<<endl;
		cout<<"Division : "<<division<<endl;
		cout<<"Address : "<<address<<endl;
	}
	void setdata(){
		cout<<"-----Enter details-----"<<endl;
		cout<<"Roll no. : ";
		cin>>rollno;
		cout<<"Name : ";
		getline(cin>>ws, name);
		cout<<"Division : ";
		cin>>division;
		cout<<"Address : ";
		getline(cin>>ws, address);
	}
	
	
};



class File{
	ofstream fout;
	ifstream fin;
	
	public:
	// Add, delete, display
	
	void insert(Student s){
		fout.open("StudentsDB.txt", ios::ate | ios::app);
		if (!fout.is_open()) return;
		
		fout<<"Roll no : "<<s.rollno<<"\t"<<"Name : "<<s.name<<"\t"<<"Divsion : "<<s.division<<"\t"<<"Address. : "<<s.address<<"\n";
		cout<<"Record added"<<endl;
		fout.close();
		
	}
	
	void display(){
		fin.open("StudentsDB.txt", ios::in);
		if (!fin.is_open()) {
			cout<<"This ran"<<endl;
			return;
		}
		
		string student;
		while(getline(fin, student)){
			cout<<student<<endl;
		}
		
		fin.close();
	}
	
	string search(string rollno){
		fin.open("StudentsDB.txt", ios::in);
		if (!fin.is_open()) return"";
		
		string student;
		bool flag = false;
		while(getline(fin, student)){
			if (student.find(rollno) != string::npos){
				flag = true;
				break;
			}
		}
		
		fin.close();
		
		if (flag){
			cout<<"Student found"<<endl;
			return student;
		}
		else{
			cout<<"Student not found"<<endl;
		}
		
		
		
		return "";
	}
	

void del(string rollno) {
    ofstream f;
    f.open("temp.txt", ios::out);
    
    fin.open("StudentsDB.txt", ios::in);
    
    string student;
    while(getline(fin, student)){
    	if (student.find(rollno) == string::npos){
    		f<<student<<endl;
		}
	}
	
	fin.close();
	f.close();
	
    remove("StudentsDB.txt");
    rename("temp.txt", "StudentsDB.txt");
    
}


	
	
};


int main() {
//	s.getdata();
	
	remove("StudentsDB");
	
	File f;
	
	// WHENEVER U DO ANY EDITS IN THE FILE, ITS STAYS THERE
	// SO DO OPERATIONS WISELY

//	f.insert(Student(24, "wqeqw", 'B', "ajsij"));
//	f.insert(Student(25, "wqweqeqw", 'A', "ertajsij"));
//	f.insert(Student(26, "wqeqtrew", 'A', "ajsretij"));
	
//	cout<<f.search("24")<<endl;
//	f.del("24");
	
	f.display();
	
	return 0;
}
