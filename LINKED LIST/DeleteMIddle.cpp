#include<iostreaM>
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
Node* deleteMiddle(Node* head){
 Node* slow = head;
 Node* fast = head;
 while(fast!=NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
 }
   slow->val = slow->next->val;
   slow->next = slow->next->next;
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
   deleteMiddle(a 
   );
   display(temp);


}