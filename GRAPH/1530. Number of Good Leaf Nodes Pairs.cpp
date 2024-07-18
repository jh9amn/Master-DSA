#include<bits/stdc++.h>
using namespace std;
int main(){}


class Solution {
public:
    void makeUnDirectGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>> &adj , unordered_set<TreeNode*> &st){
        if(root == NULL) return;

        if(root -> left == NULL and root -> right  == NULL) st.insert(root);

        if(prev != NULL) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeUnDirectGraph(root -> left, root, adj, st);
        makeUnDirectGraph(root -> right, root, adj, st);
    }
 
    int countPairs(TreeNode* root, int distance) {
        // first convert this binary tree into undirected graph
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        
        // storing Left node for finding dist
        unordered_set<TreeNode*> st;

        // S.C = O(n)
        makeUnDirectGraph(root, NULL, adj, st);     // O(n)

        int count = 0;

        // O(n^2)
        for(auto &leaf : st){           // proposanal to no of node in the tree ~ o(n)
            queue<TreeNode*> q;
            unordered_set<TreeNode*> vis;

            q.push(leaf);
            vis.insert(leaf);

            for(int level = 0; level <= distance; level++){     // only go till level <= distance
                int size = q.size();
                while(size--){                                  // level processed
                    TreeNode* curr = q.front();
                    q.pop();
                    
                    if(curr != leaf and st.count(curr)){        // leaf node to leaf node within distance
                        count++;
                    }

                    for(auto ngbr : adj[curr]){
                        if(!vis.count(ngbr)){
                            q.push(ngbr);
                            vis.insert(ngbr);
                        }
                    }

                }
            }
        }
        return count/2;
        
    }
};