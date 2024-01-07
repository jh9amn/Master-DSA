#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
           unordered_map<char,int> mp2;
        for(int i=0; i<chars.size(); i++){
            mp[chars[i]]++;
            mp2[chars[i]]++;
        }
     
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            string s = words[i];
            
            // storing every ele into mp2
            unordered_map<char,int> mp2;
            for(auto x : s){
                mp2[x]++;
            }
            
            // comparing frequency of every char of element
            bool flag = true;
            for(auto it : mp2){
                // if any time mp2 greater frequecy then don't check for that ele of string
                if(it.second > mp[it.first]){
                    flag = false;
                    break;
                }
            }
            if(flag == true) ans += s.size();
        }
        return ans;
    }
};

int main(){

}