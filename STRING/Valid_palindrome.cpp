#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 1 && s[0] >= 97 && s[0] <= 122) return true;
        
        string ans = "";
        
        // converting into lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        // adding char and numbers
        for(int i=0; i<s.size(); i++){
            if(s[i] >= 97 && s[i] <= 122 || s[i] >= 48 && s[i] <= 57){
                ans += s[i];
            }
        }
        
        // checking Plindrome
        if(ans.size() == 1) return true; 
        int i=0, j = ans.size()-1;
        while(i < j){
            if(ans[i] == ans[j]) {
                i++;
                j--;
            }
            else return false;
        }
        return true ;
    }
};


int main(){


}