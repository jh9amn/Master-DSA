//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    int sum = 0;
    void bfs(Node* root){
        queue<Node*> q;
        if(root -> left) q.push(root -> left);
        if(root -> right) q.push(root -> right);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp -> left and temp -> right){
                if(temp -> data != sum + temp -> left -> data + temp -> right -> data) {
                    sum = 0;
                    break;
                }
            }
            
            sum += temp -> data;
            
            
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
    }
    
    // void dfs(Node* root){
    //     if(root == NULL) return;
        
    //     if(root -> left and root -> right) {
    //         if(root -> data != root -> left -> data + root -> right -> data) return;
    //     }
        
    //     sum += root -> data;
        
    //     dfs(root -> left);
    //     dfs(root -> right);
    // }
    
    bool isSumTree(Node* root) {
        if(!root -> left and !root -> right) return true;
        bfs(root);
        
        // dfs(root);
        
        // cout<<sum;
        return sum == root -> data;
        // return sum - root -> data == root -> data;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;

        getline(cin, s);

        Node* root = buildTree(s);
        Solution ob;
        if (ob.isSumTree(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 1;
}
// } Driver Code Ends