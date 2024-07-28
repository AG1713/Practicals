# include<iostream>
# include<string>
# include<vector>
# include<algorithm>
using namespace std;

// Searching and sorting in vector

class info{
    string name;
    string dob;
    int telenum;
    
    public:
    int code;

    info(){}

    info(string n, string d, int t, int c){
        name = n;
        dob = d;
        telenum = t;
        code = c;
    }

    void display(){
        cout<<"Name = "<<name<<endl;
        cout<<"DOB = "<<dob<<endl;
        cout<<"Tel. no. = "<<telenum<<endl;
        cout<<"Code = "<<code<<endl;
    }
};

int search_it(vector<info> vec1, int c){
    for (int i=0 ; i<vec1.size() ; i++){
        if(vec1[i].code == c){
            return i;
        }
    }
    return -1;
}


void sort_it(vector<info> &vec1){
    for (int i=1 ; i<vec1.size() ; i++){
        info up = vec1[i];
        int j = i-1; // j+1 = i
        while((j>=0)&&(vec1[j].code>up.code)){
            vec1[j+1] = vec1[j];
            j--;
        }
        vec1[j+1] = up;
    }
}


int main(){
    vector<info> record;

    record.push_back(info("AEbc", "43", 566,4));
    record.push_back(info("ADbc", "54", 546,1));
    record.push_back(info("Abc", "543", 57,3));

    cout<<search_it(record, 1)<<endl;
    sort_it(record);
    record[0].display();
    record[1].display();
    record[2].display();



    return 0;
}