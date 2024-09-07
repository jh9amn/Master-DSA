#include<bits/stdc++.h>
using namespace std;
int main(){}



class Solution {
public:
    // dfs 2
    // here match the Nodes of linked list in Tree
    bool dfs(ListNode* head, TreeNode* root){
        if(head == NULL) return true;
        if(root == NULL) return false;

        if(head -> val == root -> val){
            head = head -> next;
            return dfs(head, root -> left) || dfs(head, root -> right);
        }
        else return false;
    }

    // dfs 1
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) return false;
        // if head -> val == root -> val then start check whole head values of linked list
        if(head -> val == root -> val) {
            if(dfs(head, root)) return true;
        }

        return isSubPath(head, root -> left) || isSubPath(head, root -> right);
    }
};


/*
STEPS:
1) dfs1 for find the matching node of linked list and tree node
2) then just start dfs2 from there to match whole linked list
3) match linked list node with Tree Nodes and do next  
4) if my linked list node == NULL means every list node is traversed, so return true
5) if my tree root == NULL return false


CONCLUSION : 
here I used 2 dfs traversals
1) dfs1 for find matchig point of linked list node and Tree node
2) dfs2 for match all the linked node to tree Node 
*/