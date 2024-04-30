//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverseList(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr){
            Node* nextCurr = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextCurr;
        }
        return prev;
    }
    
    Node* AddTwoList(Node*a , Node* b){
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        int carry = 0;
        while(a and b){
            int sum = a -> data + b -> data + carry;
            int value = sum % 10;
            carry = sum / 10;
            
            Node* dummy = new Node(value);
            temp -> next = dummy;
            
            a = a -> next;
            b = b -> next;
            temp = temp -> next;
        }
        
        while(a){
            int sum = a -> data + carry;
            int value = sum % 10;
            carry = sum / 10;
            
            Node* dummy = new Node(value);
            temp -> next = dummy;
            
            a = a -> next;
            temp = temp -> next;
        }
        while(b){
            int sum = b -> data + carry;
            int value = sum % 10;
            carry = sum / 10;
            
            Node* dummy = new Node(value);
            temp -> next = dummy;
            
            b = b -> next;
            temp = temp -> next;
        }
        
        if(carry > 0){
            Node* dummy = new Node(carry);
            temp -> next = dummy;
        }
        
        return ans -> next;
        
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // removing Zeros From Starting
       while(num1 -> next && num1->data == 0){
            num1 = num1 -> next;
       }
       while(num2 -> next && num2->data == 0){
            num2 = num2 -> next;
       }
       
       // reversing List
       num1 = reverseList(num1);
       num2 = reverseList(num2);
       
       return reverseList(AddTwoList(num1, num2));
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends