#include<bits/stdc++.h>
using namespace std;

/*
    TRIE
    ** we can insert all the num into trie into bits
    ** write search function of opposite bit to maximize XOR

    What is different to do here...
    ** sort queries in terms of mi and then insert into trie
    ** sort queries and keep index then insert in ans and findMaxXor
    
*/

// Prepare NODE sturcture..
struct Node{
    Node* links[2];

    bool containKey(int bit) {
        return (links[bit] != NULL);
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
    private:
    Node* root;
    public:
    Trie() {
        root = new Node();
    }

    void insert(int val){
        Node* node = root;

        for(int i=31; i>=0; i--){
            int bit = (val >> i) & 1;

            if(!node -> containKey(bit)) {
                node -> put(bit, new Node());
            }
            node = node -> get(bit);
        }
    } 

    int getMaxXor(int val) {
        Node* node = root;
        int maxXor = 0;

        for(int i=31; i>=0; i--){
            if(!node) break; 
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
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // add their original index into the quries..
        for(int i=0; i<queries.size(); i++) {
            queries[i].push_back(i);        // queries[i][2] == their original index
        }

        sort(begin(queries), end(queries), [] (const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        vector<int> ans(queries.size());
        // sort nums 
        sort(nums.begin(), nums.end());
        int numIndex = 0;

        // go onto the queries and insert into the trie
        for(int i=0; i<queries.size(); i++){
            int val = queries[i][0];        // x
            int comp = queries[i][1];       // m
            int idx = queries[i][2];        // original index of queries

            while (numIndex < nums.size() && nums[numIndex] <= comp) {
                trie.insert(nums[numIndex++]);
            }

            // if no number is inserted
            if(numIndex == 0) {
                ans[idx] = -1;
            }
            else {
                int maxiXOR = trie.getMaxXor(val);
                ans[idx] = maxiXOR;
            }
        }
        return ans;
    }
};

int main(){}
