#include<bits/stdc++.h>
using namespace std;
int main(){}

// Definition for singly-linked list.

 struct ListNode {
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
 };


 // Merge List using sepearate Pointers..
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(1);
        ListNode* temp = ans;
        while(list1 && list2) {
            if(list1 -> val > list2 -> val) {
                ans -> next = list2;
                list2 = list2 -> next;
            }
            else {
                ans -> next = list1;
                list1 = list1 -> next;
            }
            ans = ans -> next;
        }
        while(list1) {
                ans -> next = list1;
                ans = ans -> next;
                list1 = list1 -> next;
            }

        while(list2) {
            ans -> next = list2;
            ans = ans -> next;
            list2 = list2 -> next;
        }
        return temp -> next;
    }
};


// Recursive Approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1 -> val > list2 -> val) {
            list2 -> next = mergeTwoLists(list1, list2 -> next);
            return list2;
        }
        else {
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        }
    }
};