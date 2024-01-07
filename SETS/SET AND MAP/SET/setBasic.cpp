/*
-> In set elements are store in random order
-> All the operation perform in o(1) t.c like  insert ,erase,
-> the main feature is that it doesnot contain the dublicate value
-> there is another way to find target in set like if(s.find(target) != s.endl) cout<<"Exist"
*/
#include<iostream>
#include<unordered_set>
using namespace std;
 int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);        // 5 1 2 3 4 
    // does not store dublicate element in set s ...
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);        // 5 1 2 3 4   
    
    // erase function is used to erase the element in the set
    // s.erase(2);         // 5 1 3 4 

    int target  = 4;
    if(s.find(target) != s.end()) { // means target exist
        cout<<"Exist"<<endl;
    }       
    else{
        cout<<"Not exits"<<endl;
    }

    // for printing (in random order)
    for(int ele : s){
        cout<<ele<<" ";
    }
 }