#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        //Not working Properly need Modification
//         queue<int> stu;
//         stack<int> sand;
        
//         for(int i=0; i<students.size(); i++){
//             stu.push(students[i]);
//         }
//         for(int i=0; i<sandwiches.size(); i++){
//             sand.push(sandwiches[i]);
//         }
        
//         int notEat = 0;
//         while(stu.size() > 0  && notEat != stu.size()){
//             int q = stu.front();
//             stu.pop();
//             int s = sand.top();
            
//             if(q == s){
//                 sand.pop();
//             }
//             else{
//                 stu.push(q);
//                 notEat++;
//             }
//         }
//         return stu.size() == 0 ? 0 : notEat;
        
        
        
        // Approach 2
        // count no of student like 1 sandwitch and 0 sandwitch
        // traverse on sandwitch if that idx sandwitch have in no of sandwitch then defenetly he will eat 
        int arr[2] = {0};
        for(int i=0; i<students.size(); i++){
            arr[students[i]]++;
        }
        
        int n = students.size();
        for(int i=0; i<sandwiches.size(); i++){
            int sand = sandwiches[i];
            if(arr[sand] > 0) arr[sand]--;
            else return n - i;
        }
        return 0;
    }
};


int main(){

}