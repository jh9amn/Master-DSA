#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> s;
        s.insert(wordList.begin(), wordList.end());  // for fast comparision
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        s.erase(beginWord);
        
        // BFS for the level..
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            string original = word;
            if(word == endWord) return level;
            int size = word.size();
            for(int i=0; i<size; i++){
                for(char c = 'a'; c <= 'z'; c++){
                   word[i] = c; // changing the ith alphabat in word to find the new matching word
                   if(s.find(word) != s.end()){
                       q.push({word,level+1});
                       s.erase(word);
                   }
                }
                // putting the original word to compare again
                word = original;
            }
        }
        return 0;
    }
};
int main(){

}