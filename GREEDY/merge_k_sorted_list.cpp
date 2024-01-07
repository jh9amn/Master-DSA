
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class cmp{
    public: 
    bool operator()( const ListNode* l1,ListNode* l2){
    return l1->val > l2->val ;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , cmp> pq;

        for(int i=0; i<lists.size(); i++){
            if(lists[i] == NULL) continue;
            pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode (-1);
        ListNode* ptr = dummy;
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            if(curr -> next != NULL){
                pq.push(curr -> next);
            }
                ptr -> next = curr;
                ptr = ptr->next;
        }
            return dummy->next;
    }
};

class ListNode{
    public:
    int val;
    ListNode* next;
    
};

int main(){
    
}

