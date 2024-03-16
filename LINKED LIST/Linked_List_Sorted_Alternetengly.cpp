#include<bits/stdc++.h>
using namespace std;

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    
    Node* mergeTwoLists(Node* a, Node* b) {
        Node* c = new Node(100);
        Node* temp = c;
        while(a!=NULL && b!=NULL){
            if(a->data<=b->data){
                temp->next = a;
                temp = temp->next;
                a = a->next;
            }
            else {
                temp->next = b;
                temp = temp->next;
                b = b->next;
            }
        }
        if(a==NULL){
            temp->next = b;
        }
        else {
            temp->next = a;
        }
        return c->next;
    }
    
    void reverse(Node *&head){
        Node* prev=NULL, *curr=head, *next;
        
        while(curr){
            next=curr->next;
            curr->next= prev;
            prev = curr;
            curr=next;
        }
        head=prev;
    }
    
    void splitList(Node*head, Node **Ahead, Node**Dhead){
        *Ahead=new Node(0);
        *Dhead=new Node(0);
        
        Node*ascn= *Ahead;
        Node*dscn= *Dhead;
        Node* curr=head;
        while(curr){
            ascn->next=curr;
            ascn=ascn->next;
            curr=curr->next;
            
            if(curr){
                dscn->next=curr;
                dscn=dscn->next;
                curr=curr->next;
            }
        }
        
        ascn->next=NULL;
        dscn->next=NULL;
        
        *Ahead=(*Ahead)->next;
        *Dhead=(*Dhead)->next;
        
        return;
    }
    
    
    // your task is to complete this function
    void sort(Node **head)
    {
         // Code here
         Node*Ahead, *Dhead;
         splitList(*head, &Ahead, &Dhead);
         
         reverse(Dhead);
         
         *head=mergeTwoLists(Ahead, Dhead);
         
         return;
    }
};
    
int main(){

}