/* accessing the value of other node using any other node */
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

int main(){
    Node a(20);
    Node b(30);
    Node c(40);
    Node d(50);

    a.next = &b;
    b.next = &c;
    c.next = &d;

    cout<<"1st "<<a.next->val<<endl;        // these both are same
    cout<<"First "<<(*(a.next)).val<<endl;

    cout<<"2nd "<<((a.next)->next)->val<<endl;    
    cout<<"Second "<<(*((*(a.next)).next)).val<<endl;

    cout<<"3rd "<<(((a.next)->next)->next)->val<<endl;
    cout<<"Third "<<(*((*((*(a.next)).next)).next)).val<<endl;
    
   }