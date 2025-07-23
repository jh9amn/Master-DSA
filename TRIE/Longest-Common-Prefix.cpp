#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool flag = false;

    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    bool isEnd() {
        return flag;
    }

    void setEnd() {
        flag = true;
    }
};


class Trie {
private:
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;

        for(char &ch: word){
            if(!node -> containKey(ch)) {
                node -> put(ch, new Node());
            }
            node = node->get(ch);
        } 
        node -> setEnd();
    }

    bool checkPrefixExist(string &word) {
        Node* node = root;

        for(char &ch : word){
            if(!node->containKey(ch)) return false;
            node = node->get(ch);
            if(!node->isEnd()) return false;
        }
        return true;
    }
};


string longestCommonPrefix(vector<string> &arr, int n)
{   
    Trie trie;
    for(auto &it : arr) {
        trie.insert(it);
    }

    string longest = "";
    for(auto &word : arr){
        if(trie.checkPrefixExist(word)){                                // lexicographically smallest
            if(longest.size() < word.size() || 
              (longest.size() == word.size() && longest > word)) {
                longest = word;
            }
        }
    }

    return longest == "" ? "None" : longest;
}


int main() {
    vector<string> words = {"apple", "app", "apricot", "ape"};
    int n = words.size();

    string result = longestCommonPrefix(words, n);
    cout << "Longest valid prefix word: " << result << endl;

    return 0;
}
