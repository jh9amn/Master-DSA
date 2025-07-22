
#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    int getEnd() {
        return cntEndWith;
    }

    int getPrefix() {
        return cntPrefix;
    }

    void deleteEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
    }
};


class Trie{
    private:
    Node* root;

    public:

    Trie(){
        root = new Node();
    }

    // O(n)
    void insert(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); ++i) {
            if(!node -> containKey(word[i])) {
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
            node -> increasePrefix();
        }
        node -> increaseEnd();
    }

    // O(n)
    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node -> containKey(word[i])) {
                node = node -> get(word[i]);
            }
            else return 0;
        }

        return node -> getEnd();    // trie contain word return endWith;
    }

    // O(n)
    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(node -> containKey(word[i])) {
                node = node -> get(word[i]);
            }
            else return 0;
        }
        return node -> getPrefix();     // trie contain word prefrix return prefix;
    }

    // O(n)
    void erase(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(node -> containKey(word[i])) {
                node = node -> get(word[i]);
                node -> reducePrefix();
            }
            else return;
        }
        node -> deleteEnd();
    }
};


int main(){}