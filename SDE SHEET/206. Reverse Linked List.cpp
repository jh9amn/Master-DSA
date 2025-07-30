#include<bits/stdc++.h>
using namespace std;
int main(){}



 /*Definition for singly-linked list.*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

/* (O(n) time, O(1) space): Reverse by changing pointers */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr) {
            ListNode* store = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = store;
        }
        return prev;
    }
};


/* Reversing Array Way... O(n^2) */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // it will give the ith Node..
        function<ListNode*(ListNode*, int)> getNode = [&] (ListNode* temp, int n) -> ListNode* {
            for(int i=1; i<=n; i++) {
                temp = temp -> next;
            }
            return temp;
        };

        ListNode* temp = head;
        int i=0;
        int j = -1;
        while(temp) {
            temp = temp -> next;
            j++;
        }

        while(i < j) {
            ListNode* leftNode = getNode(head, i++);
            ListNode* rightNode = getNode(head, j--);

            swap(leftNode -> val, rightNode -> val);
        }

        return head;
    }
};