# include<iostream>
# include<map>

using namespace std;

int main(){
    map<string, int> population_map;

    population_map.insert(pair<string, int>("maharashtra", 10000));
    population_map.insert(pair<string, int>("rajasthan", 20000));
    population_map.insert(pair<string, int>("goa", 12000));
    population_map.insert(pair<string, int>("telengana", 104500));
    population_map.insert(pair<string, int>("tamilnadu", 101589));
    population_map.insert(pair<string, int>("kerala", 10000));
    population_map.insert(pair<string, int>("karnataka", 1568900));
    population_map.insert(pair<string, int>("manipur", 10780));
    population_map.insert(pair<string, int>("hydrabad", 1789500));

    map<string, int>::iterator iter1;

    string state = "hydrabad";

    for(iter1 = population_map.begin() ; iter1!=population_map.end() ; iter1++){
        if(iter1->first == state){
            cout<<iter1->second<<endl;
            break;
        }
    }
    cout<<iter1->second<<endl;
    cout<<population_map.end()->first<<endl;
    if(iter1==population_map.end()){
        cout<<"Not found"<<endl;
    }


    return 0;
}