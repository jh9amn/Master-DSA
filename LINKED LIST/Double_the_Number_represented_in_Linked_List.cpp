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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr){
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        int carry = 0;
        ListNode* temp = head;
        
        ListNode* ans = new ListNode(-1);
        ListNode* res = ans;
        
        while(temp){
            int value = temp -> val * 2 + carry;
            carry = value / 10;
            value %= 10;
            ListNode* dummy = new ListNode(value);
            ans -> next = dummy;
            temp = temp -> next;
            ans = ans -> next;
        }
        
        if(carry != 0){
            ListNode* dummy = new ListNode(carry);
            ans -> next = dummy;
        }
        
        res = res -> next;
        res = reverseList(res);
        return res;
    }
};

int main(){

}