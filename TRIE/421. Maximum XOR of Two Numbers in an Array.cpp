#include<bits/stdc++.h>
using namespace std;
int main(){}


struct Node{
    Node* link[2];

    bool containKey(int bit) {
        return (link[bit] != NULL);
    }

    void put(int bit, Node* node) {
        link[bit] = node;
    }

    Node* get(int bit) {
        return link[bit];
    }
};

class Trie{
    private:
    Node* root;
    public:
    Trie() {
        root = new Node();
    }

    void insert(int val) {
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (val >> i) & 1;
            if(!node -> containKey(bit)){
                node -> put(bit, new Node());
            }
            node = node -> get(bit);
        }
    }

    // opposite bits in XOR = 1;
    // same bits in XOR = 0;
    // to maximize XOR always go for opposte bit number...
    
    int getMax(int val) {
        Node* node = root;
        int maxXor = 0;
        for(int i=31; i>=0; i--){
            int bit = (val >> i) & 1;
            // find opposite bit, make help to make maximize XOR
            if(node -> containKey(1 - bit)) {
                // put set bit at that ith idx to maximize XOR value
                maxXor = maxXor | (1 << i);
                // move their where we get oppsite bit to maximize
                node = node -> get(1 - bit);
            }
            else {
                node = node -> get(bit);
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    Trie trie;
    int findMaximumXOR(vector<int>& nums) {
        
        for(auto num : nums) trie.insert(num);
        int maxResult = 0;
        for (auto num : nums) {
            maxResult = max(maxResult, trie.getMax(num));
        }
        return maxResult;
    }
};