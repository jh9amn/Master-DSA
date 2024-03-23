#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
      ListNode* reverseList(ListNode* head){
      ListNode* curr = head;
      ListNode* prev = NULL;
      ListNode* Next = NULL;
      while(curr){
          Next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = Next;
      }
      return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int n = 1;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow->next = NULL;
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        ListNode* tempA = a;
        ListNode* tempB = b;

        while(tempA && tempB){
            tempC->next = tempA;
            tempA = tempA->next;
            tempC = tempC->next;
            tempC->next = tempB;
            tempB = tempB->next;
            tempC = tempC->next;
        }
        tempC->next = tempA;
        head = c->next;
    }
};


int main(){


}