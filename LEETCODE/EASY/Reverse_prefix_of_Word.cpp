#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        if(word.size() == 1) return word;
        int n = word.size();
        
        for(int i=0; i<word.size(); i++){
            if(word[i] == ch) {
                int j = 0;
                while(j<=i){
                    swap(word[i],word[j]);
                    j++;
                    i--;
                }
                break;
            }
        }
        return word;
    }
};




int main(){


}