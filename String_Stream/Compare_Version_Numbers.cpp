// https://leetcode.com/problems/compare-version-numbers/

#include<bits/stdc++.h>
#include<sstream>
using namespace std;

class Solution {
public:
    // cutting and storing all the substring of s from char '.'
    void stream(string s, vector<string> &v){
        stringstream ss(s); 
        string token = "";
        while(getline(ss,token, '.')){
            v.push_back(token);
        }
    }
    
    int compareVersion(string version1, string version2) {
        vector<string> v1;
        vector<string> v2;
        
        stream(version1, v1);
        stream(version2, v2);
        
        int n = v1.size();
        int m = v2.size();
        
        int i = 0;
        int j = n > m ? n : m;
        
        while( i < j){
            int a = (i < n) ? stoi(v1[i]) : 0;
            int b = (i < m) ? stoi(v2[i]) : 0;
            
            if(a > b) return 1;
            else if(a < b) return -1;
            else i++;   
        }
        return 0;
    }
};


int main(){
}