#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];

    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

int distinctSubstring(string &word) {
    Node* root = new Node();
    int cnt = 0;   

    for(int i=0; i<word.size(); i++){
        Node* node = root;
        for(int j=i; j<word.size(); j++){
            if(!node -> containKey(word[j])) {
                cnt++;
                node -> put(word[j], new Node());
            }
            node = node -> get(word[j]);
        }
    }
    return cnt;
}

int main(){}
