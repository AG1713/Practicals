# include<iostream>
using namespace std;

// Name, class, division, rollno, address, date of birth, blood group, contact, phn no., license no. and other
// constructor-done, default contructor-done, copy contructor, static member functions, friend class, this pointer-done,
// inline code, dynamic memory allocation (new and delete), exception handling


class Biodata{
    private:
    static int total;

    string name;
    string Class;
    char division;
    int rollno;
    string address;
    string DOB;
    string blood_group;
    string contact; // mail id
    int phn_no;
    int license_no;

    public:
    Biodata(){}; // Default contructor

    Biodata(string name, string Class, char division, int rollno){ // Contructor
        name = "";
        Class = "";
        division = '0';
        rollno = -1;
        address = "";
        DOB = "";
        blood_group = "";
        contact = "";
        phn_no = -1;
        license_no = -1;

        cout<<"Basic info"<<endl;
        Basic_info(name, Class, division, rollno);
    }

    void Basic_info(string name, string Class, char division, int rollno){
        this->name = name; // this pointer
        this->Class = Class;
        this->division = division;
        this->rollno = rollno;
    }


};


int main(){
    
    return 0;
}