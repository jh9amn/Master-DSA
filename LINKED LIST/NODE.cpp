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

int main(){
    Node a(20);
    Node b(30);
    Node c(40);
    Node d(50);

    a.next = &b;
    b.next = &c;
    c.next = &d;

   Node temp = a;

   while(temp.next!=NULL){
      cout<<temp.val<<" ";
      temp = *(temp.next);
   }
    
}