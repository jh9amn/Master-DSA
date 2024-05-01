//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    struct Node* arrangeCV(Node* head) {
        // string vowel = "";
        
        // Node* temp = head;
        // Node* prev = temp;
        
        // while(temp){
        //     if(temp -> data == 'a' or temp -> data == 'e' or temp -> data == 'i' or temp -> data == 'o' or temp -> data == 'u'){
        //         vowel += temp -> data;
                
        //         prev -> next = temp -> next;
        //     }
        //     prev = temp;
        //     temp = temp -> next;
        // }
        

        
        // int i = 0;
        // int j = vowel.size();
        
        // reverse(vowel.begin(), vowel.end());
        
        // while(i<j){
        //     Node* dummy = new Node(vowel[i]);
        //     dummy -> next = head;
        //     i++;
        //     head = dummy;
        // }
        
        
        
        Node* temp = head;
        Node* vow = new Node('-1');
        Node* vowel = vow;
        Node* conso = new Node('-1');
        Node* consonent = conso;
        
        while(temp){
            if(temp -> data == 'a' or temp -> data == 'e' or temp -> data == 'i' or temp -> data == 'o' or temp -> data == 'u'){
                Node* dummy = new Node(temp -> data);
                vow -> next = dummy;
                vow = vow -> next;
            }
            else{
                Node* dummy = new Node(temp -> data);
                conso -> next = dummy;
                conso = conso -> next;
            }
            
            temp = temp -> next;
        }
        
        vow -> next = consonent -> next;
        
        return vowel -> next;;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends