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

class LinkedList{
public:
    Node* head = NULL;
    Node* tail = NULL; 
    int size = 0;

        // LinkedList(){
        //     head = tail = NULL;
        //     size = 0;
        // }

        void insertAtTail(int val) {
            Node*temp = new Node(val);
            if(size == 0) head = tail = temp;
            else{
                tail->next = temp;
                tail = temp;
            }size++;
        }

        void insertAtHead(int val){
            Node* temp = new Node(val);
            if(size == 0) head = tail = temp;
            else{
                temp ->next = head;
                head = temp;
            }size++;
        }

        void insertAtIdx(int idx,int val){
            if(idx < 0 || idx > size)  cout<<"Invalid Index"<<endl;
            else if(idx == 0) insertAtHead(val);
            else if(idx == size) insertAtTail(val);
            else{
                Node* t = new Node(val);
                Node* temp = head;
                for(int i=1; i<=idx-1; i++){
                    temp = temp-> next;
                }
                t->next = temp->next;
                temp->next = t;
                size++;
            } 
        }

        int getAtIdx(int idx ){
            if(idx < 0 || idx >= size) {
                cout<<"Invalid Index "<<endl;
                return -1;
            }
            else if(idx == 0) return head -> val;
            else if(idx == size-1) return tail -> val;
            else{
                Node* temp = head;
                for(int i=1; i<=idx; i++){
                    temp = temp -> next;
                }
                return temp -> val;
            }
        }

        void deleteAtHead(){
            if(size == 0) {
                cout<<"List is empty";
                return ;
            }
            head = head -> next;
            size --;
        }

        void deleteAtTail(){
            if(size == 0) {
                cout<<"List is Empty";
                return;
            } 
            Node* temp = head;
            while(temp -> next != tail){
                temp = temp -> next;
            }
            temp -> next = NULL;
            tail = temp;
            size--;
        }

        void deleteAtIdx(int idx) {
            if(size == 0){
                cout<<"List is Empty";
                return;
            }
            else if(idx < 0 || idx >= size){
                cout<<"Invalid Index"<<endl;
                return;
            }
            else if(idx == 0) return deleteAtHead();
            else if(idx == size-1) return deleteAtTail();
            else{
                Node* temp = head;
                for(int i=1; i<=idx-1; i++){
                    temp = temp -> next;
                }
                temp -> next = temp -> next -> next;
                size--;
            }
        }

        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->val<<" ";
                temp = temp->next;
            }cout<<endl;
        }
        
};
int main(){
    LinkedList ll;
    ll.insertAtTail(10);       // 10
    ll.display();
    ll.insertAtTail(20);       // 10 20
    ll.insertAtHead(30);       // 30 10 20
    ll.insertAtIdx(1,40);      //30 40 10 20
    ll.display();
    ll.insertAtHead(50);       // 50 30 40 10 20
    ll.insertAtIdx(3,60);      // 50 30 40 60 10 20
    ll.display();
    ll.deleteAtHead();        // 30 40 60 10 20
    ll.display();
    ll.deleteAtTail();
    ll.display();             // 30 40 60 10
    cout<<ll.getAtIdx(3)<<endl;
    ll.insertAtHead(100);    // 100 30 40 60 10
    ll.display();
    ll.deleteAtIdx(3);       // 100 30 40 10  
    ll.display();

}