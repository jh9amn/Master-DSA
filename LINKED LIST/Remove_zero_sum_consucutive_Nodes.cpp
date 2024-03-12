#include<bits/stdc++.h>
using namespace std;

// Source : https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    // T.C = O(n) + O(n)    S.C = O(n)
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* DummyHead = new ListNode(0);
        DummyHead->next = head;
        
        int prefixSum = 0;
        ListNode* temp = DummyHead;
        
        map<int,ListNode*> mp;
        // Traverse and add to map and update prefix sum
        while(temp != NULL){
            prefixSum += temp->val;
            // in map prefixSum and address of that place
            // if there more place with same prefix sum then map will store last place
            // skip that much place which has same prefix sum and jump towards it next 
            mp[prefixSum] = temp;
            temp = temp->next;
        }
        
        temp = DummyHead;
        prefixSum = 0;
        // Here Match Prefix present then temp-next  = prefixSum->next
        while(temp != NULL){
            prefixSum += temp->val;
            // if we get prefixSum in map then jump towards it prefixSum->next to skip that much index
            if(mp.find(prefixSum) != mp.end()){
                temp->next = mp[prefixSum]->next;
            }
            temp = temp->next;
        }
        return DummyHead->next;
    }
};


int main(){


}