//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

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
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
  // Count Inversions Uisng merge sort
  
    // int count;
    // void merge(vector<int> &arr, int low, int mid, int high)
    // {   
    //     vector<int> temp;
    //     //both array starting idx
    //     int left = low;             //  left side starting idx
    //     int right = mid + 1;        // right side starting idx
        
    //     // Merging left side array and right side array
    //     while( left <= mid &&  right <= high){
    //         if(arr[left] <= arr[right]){
    //             temp.push_back(arr[left]);
    //             left++;
    //         }
    //         else{
    //             count += mid - low;
    //             temp.push_back(arr[right]);
    //             right++;
    //         }
    //     }
        
    //     // if right side of array is Over and left side of array has some element left
    //     while( left <= mid ){
    //         temp.push_back(arr[left]);
    //         left++;
    //     }
    //     // if left side of array is Over and right side of array has some element left
    //     while( right <= high ){
    //         temp.push_back(arr[right]);
    //         right++;
    //     }
        
    //     for(int i=low; i <= high; i++){
    //         arr[i] = temp[ i- low];
    //     }
    // }  
    
    // void mergeSort(vector<int> &arr, int low, int high)
    // {
    //     if( low == high) return;
    //     int mid =  (low+high) / 2;
    //     mergeSort(arr, low, mid);
    //     mergeSort(arr, mid + 1, high);
    //     merge(arr, low, mid, high);
    // }
    
    void Inorder(Node* root, vector<int> &inorder){
        if(root == NULL) return;
        Inorder(root -> left, inorder);
        inorder.push_back(root -> data);
        Inorder(root -> right, inorder);
    }

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        vector<int> inorder;
        Inorder(root, inorder);
        
        // how many ele less than prev ele then count++
        // Count Inversions code
        if(inorder.size()<=1)return 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i=0;i<inorder.size();i++)pq.push({inorder[i],i});
        
        int ans=0;
        vector<int> x;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            // Upper bound function gives the just greater value index to that given number in the fuction 
            int cnt=upper_bound(x.begin(),x.end(),it.second)-x.begin();
            ans += it.second-cnt;
            x.insert(upper_bound(x.begin(),x.end(),it.second),it.second);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends