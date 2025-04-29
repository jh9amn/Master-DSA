//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        
        if(!head or !head -> next) return head;
        // code here
        Node *zero = new Node(-1);
        Node *one = new Node(-1);
        Node *two = new Node(-1);
        
        Node *zeroNext = zero;
        Node *oneNext = one;
        Node *twoNext = two;
        
        while(head) {
            if(head -> data == 0) {
                zeroNext -> next = head;
                zeroNext = zeroNext -> next;
            }
            
            else if(head -> data == 1){
                oneNext -> next = head;
                oneNext = oneNext -> next;
            }
            
            else if(head -> data == 2){
                twoNext -> next = head;
                twoNext = twoNext -> next;
            }
            
            
            head = head -> next;
        }
        
        zeroNext -> next = one -> next ? one -> next : two -> next;
        oneNext -> next = two -> next;
        twoNext -> next = NULL;

        return zero -> next ? zero -> next : (one -> next ? one -> next : two -> next);
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends