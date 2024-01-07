#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i=0; 
        int j = people.size()-1;
        int boat = 0;
        while(i<=j){
            if(people[i] + people[j] > limit){
                boat++;
                j--;
            }
            else {
                i++;
                j--;
                boat++;
            }
        }
        return boat;
    }
};

int main(){
    vector<int> people = {3,2,2,1};
    int limit = 3;
    Solution ques;
    cout<<ques.numRescueBoats(people,limit);
}