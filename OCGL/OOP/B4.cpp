# include<iostream>
# include<fstream>
using namespace std;

int main(){
    fstream f;
    f.open("Thisthis.txt", ios::out);
    f<<"This is a line from the text";
    if(f){
        cout<<"File is open"<<endl;
    }

    f.close();



    f.open("Thisthis.txt", ios::in);
    char ch;
    cout<<"File content :"<<endl;
    while(f){
        f>>ch;
        cout<<ch;
    }
    f.close();


    return 0;
}