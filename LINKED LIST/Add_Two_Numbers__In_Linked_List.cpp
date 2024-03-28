#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode* res = new ListNode(-1);
        // traversing for res using ans
        ListNode* ans = res;
        
        int carry = 0;
                
        while(a != NULL and b != NULL){
            int sum = a ->val + b ->val + carry;
            
            int temp = sum % 10;
            carry= sum / 10 ;
            
            ListNode* dummy = new ListNode(temp);
            ans ->next = dummy;
            
            a = a -> next;
            b = b -> next;
            ans = ans ->next;
            
        }
        
        while(a != NULL){
            int sum = a ->val + carry;
            int temp = sum % 10;
            carry = sum / 10;
            
            ListNode* dummy = new ListNode(temp);
            ans ->next = dummy;
            
            a  = a -> next;
            ans = ans -> next;
            
        }
        
        while(b != NULL){
            int sum = b ->val + carry;
            int temp = sum % 10;
            carry = sum / 10;
            
            ListNode* dummy = new ListNode(temp);
            ans ->next = dummy;
            
            b = b -> next;
            ans = ans -> next ;
        }
        
        if(carry > 0){
            ListNode* dummy = new ListNode(carry);
            ans ->next = dummy;
        }
        
        return res->next; 
    }
};


int main(){


}