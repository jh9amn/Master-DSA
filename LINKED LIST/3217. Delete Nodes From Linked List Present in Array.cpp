#include<bits/stdc++.h>
using namespace std;
int main(){}

// 3217. Delete Nodes From Linked List Present in Array


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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> mark(1e5+1, 0);

        for(auto it : nums){
            mark[it] = 1;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            if(mark[curr -> val]){
                // if the deletion node is head then
                if(prev == NULL){
                    head = head -> next;
                    curr -> next = NULL;
                    curr = head;
                }
                else{
                    prev -> next = curr -> next;
                    curr -> next = NULL;
                    curr = prev -> next; 
                }
            }
            else {
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;
    }
};