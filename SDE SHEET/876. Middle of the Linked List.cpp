#include<bits/stdc++.h>
using namespace std;
int main(){}

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while(temp) {
            n++;
            temp = temp -> next;
        }

        for(int i=0; i<n/2; i++){
            head = head -> next;
        }
        return head;
        
    }
};