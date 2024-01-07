#include<iostream>
using namespace std;
class pallindrome{
public:
    int val;
    pallindrome* next;
        void pallin(int val){
            this->val = val;
            this->next = next ;
        }
    void reverse(){

    }
    void middle(pallindrome* head){
        // pallindrome* ;
    }

};


 int main(){
    pallindrome* a = new pallindrome(1);
    pallindrome* b = new pallindrome(2);
    pallindrome* c = new pallindrome(3);
    pallindrome* d = new pallindrome(3);
    pallindrome* e = new pallindrome(2);
    pallindrome* f = new pallindrome(1);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    middle(a);
     

 }