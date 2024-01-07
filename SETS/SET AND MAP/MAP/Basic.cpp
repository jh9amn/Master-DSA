#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<string,int> m;

    // We can insert in map using pair
    pair<string,int> p1;
    p1.first = "Aman";
    p1.second = 12;
    pair<string,int> p2;
    p2.first = "Niraj";
    p2.second = 7;
    pair<string,int> p3;
    p3.first = "Rajeev";
    p3.second = 8;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);

    // ANOTHER WAY TO INSERT IN MAP
    m["AJAY"] = 20;
    m["Raghav"] = 40;


    // this is a way to print using the for each loop
    // there is also a another way using the auto keyword at the place of pair<string,int>
    // it always printing in random order

    // for(pair<string,int> p : m){
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }

    // to find size of map
    cout<<m.size()<<endl;

    // Erase the element from the MAP
    m.erase("AJAY");

    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }

    if(m.find("Aman") != m.end()){
        cout<<"Present"<<endl;
    }
}