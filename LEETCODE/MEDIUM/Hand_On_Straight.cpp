#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if(hand.size() % groupSize != 0) return false;
        
        // ordered map
        map<int, int> mp;
        
        for(auto x : hand){
            mp[x]++;        // O(nlongn)
        }
        
        while(!mp.empty()){     // O(n * groupSize) 
            auto curr = mp.begin() -> first;
            
            for(int i=0; i<groupSize; i++){
                if(mp[curr + i] == 0) {     // yes clash
                    return false;
                }
                mp[curr + i]--;
                if(mp[curr + i] == 0) {
                    mp.erase(curr + i);
                }
            }   
        }
        
        return true;
        
    }
};

int main(){

}