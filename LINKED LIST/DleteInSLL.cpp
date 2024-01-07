#include<iostream>
using namespace std;
class Node{
 public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

Node *deleteNode(Node* head,Node* target)
{
    if(head == target){
        head = head->next;
    }
    Node* temp = head;
    while(temp->next != target){
        temp = temp->next;
    }
    temp -> next = temp->next->next;
    return head;
}

// When We have given targetValue not the target Node
Node* deleteNodeVal(Node* head,int targetVal)
{
    if(head->val == targetVal){
        head = head->next;
    }
    while(head->next->val != targetVal){
        head = head->next;
    }
    head -> next = head->next->next;
    return head;
}

 void display(Node* head){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->val<<" ";
                temp = temp->next;
            }cout<<endl;
}

int main(){
   Node* a = new Node(10);
   Node* b = new Node(20);
   Node* c = new Node(30);
   Node* d = new Node(40);

   a->next = b;
   b->next = c;
   c->next = d;
   Node* temp = a;
    display(temp);
   deleteNode(a,c);
   display(temp);
   deleteNodeVal(a,40);
   display(temp);


}