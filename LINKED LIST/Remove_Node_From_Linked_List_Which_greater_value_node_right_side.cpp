#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // List Reverse
    ListNode* reverseList(ListNode* head){ 
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            ListNode* nextCurr = curr ->next;
            curr -> next = prev;
            prev = curr;
            curr = nextCurr;
        }
        return prev;
    }
    
    
    ListNode* removeNodes(ListNode* head) {
// Approach 1 usng Stack
// T.C = O(n)   S.C = O(n)
//         stack<int> st;
//         ListNode* curr = head;
//         while(curr){
//             st.push(curr -> val);
//             curr = curr -> next;
//         }
        
//         int maxi = st.top();
//         st.pop();
//         ListNode* ans = new ListNode(maxi);
        
//         while(!st.empty()){
//             int currVal = st.top();
//             st.pop();
//             if(currVal < maxi){         // maxi > then delete that node
//                 continue;
//             }
//             else{
//                 ListNode* dummy = new ListNode(currVal);
//                 dummy -> next = ans;
//                 ans = dummy;
//                 maxi = currVal;
//             }
//         }
//         return ans;
        
        
        
        
// Approach 2 Using Recursion
// T.C = O(n) S.c = O(1) + auxilary stack
//         if(head == NULL or head -> next == NULL) return head;
        
//         ListNode* nextNode = removeNodes(head -> next);
        
//         // at End se
//         if(head -> val < nextNode -> val){
//             delete head;
//             return nextNode;
//         }
        
//         head -> next = nextNode;
//         return head;
        
       
        
        
// Approach 3 using reversList
// T.C = O(1) S.C = O(1);
        head = reverseList(head);
        ListNode* curr = head;
        ListNode* prev = NULL;
        int maxi = -1;
        
        while(curr){
            maxi = max(maxi, curr -> val);
            
            if(curr -> val < maxi){
                prev -> next = curr -> next;
                ListNode* temp = curr;
                curr = curr -> next;
                delete(temp);
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }
        head = reverseList(head);
        return head;
    }
};


int main(){

}