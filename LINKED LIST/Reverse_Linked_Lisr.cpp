#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head){
      // if(head==NULL || head->next==NULL) return head;
      // ListNode* newHead = reverseList(head->next);
      // head->next->next = head;
      // head->next = NULL;
      // return newHead;
        
      
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
};



int main(){


}