// https://leetcode.com/problems/lru-cache/
class LRUCache {
private:
    class Node{
        public:
        int val, key;
        Node* prev;
        Node* next;
        Node(int k, int v ){
            key = k;
            val = v;
            prev = next = NULL;
        }
    };


    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int capacity;

    // most recent used node
    void insertAfterHead(Node* node){
        Node* temp = head -> next;

        head -> next = node;
        node -> prev = head;

        temp -> prev = node;
        node -> next = temp;
    }

    // delete the least recent used node
    void deleteNode(Node* node){
        Node* prevNode = node -> prev;
        Node* nextNode = node -> next;

        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }
    
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        // If present then replace at most recent place and retun the value 
        if(mp.count(key)) {
            Node* temp = mp[key];
            deleteNode(temp);
            insertAfterHead(temp);
            return mp[key]-> val;
        }
        // else -1 
        else return -1;
    }
    
    void put(int key, int value) {
        // if key already present in map then just update the value..
        if(mp.count(key)) {
            Node* existing = mp[key];
            deleteNode(existing);           
            mp.erase(key);
        }

        // else not prensent have two cases
        // 1) capicity is full then remove the least recent and add the new node at most recent place (near head), update the map also
        // 2) capacity is not full then add the node at most recent place(nead head) and update it into map 
        if(capacity == mp.size()){
            Node* lru = tail -> prev;

            deleteNode(lru);
            mp.erase(lru -> key);
        }

        Node* newNode = new Node(key, value);
        insertAfterHead(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
