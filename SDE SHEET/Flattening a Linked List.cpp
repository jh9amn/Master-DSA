/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  private:
    Node *merge(Node* a, Node* b){
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while(a and b){
            if(a-> data > b -> data){
                temp -> bottom = b;
                b = b -> bottom;
            }
            else{
                temp -> bottom = a;
                a = a -> bottom;
            }
            temp = temp -> bottom;
        }
        
        if(a) temp -> bottom = a;
        else temp -> bottom = b;
        
        return dummy -> bottom;
    }
  public:
    Node *flatten(Node *root) {
        /* Brute Force */
        Node* temp = root;
        
        vector<int> val;
        
        while(temp){
            Node* temp2 = temp;
            
            while(temp2){
                val.push_back(temp2->data);
                temp2 = temp2 -> bottom;
            }
            
            temp = temp -> next;
        }
        
        sort(begin(val), end(val));
        
        Node* temp3 = new Node(-1);
        Node* ans = temp3;
        
        for(auto it : val){
            Node* d = new Node(it);
            temp3 -> bottom = d;
            temp3 = temp3 -> bottom;
        }
        
        return ans -> bottom;
        
        
        
        
        
        
        /* Recursive Optimized Approach */
        if(root == NULL or root -> next == NULL){
            return root;
        }
        
        Node* temp = flatten(root -> next);
        
        root = merge(root, temp);
        
        return root;
    }
};
