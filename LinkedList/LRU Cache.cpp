// https://leetcode.com/problems/lru-cache/submissions/

class LRUCache {
public:
    int cap;
    class node {
        public : 
        int key;
        int val;
        node* next;
        node* prev;
        node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };
    unordered_map<int, node*> mp;
    
    node* head = new node(-1, -1); 
    node* tail = new node(-1, -1); 
    
    void addNode(node * newNode) {
        auto t = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = t;
        t->prev = newNode;
    }
    
    void deleteNode(node * delNode) {
        auto n = delNode->next;
        auto p = delNode->prev;
        n->prev = p;
        p->next = n;
    }
    
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
        head->prev=nullptr;
        tail->next=nullptr;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            auto n = mp[key];
            deleteNode(n);
            addNode(n);
            mp[key] = head->next;
            return head->next->val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()) {
            auto x = mp[key];
            deleteNode(x);
            node * newNode = new node(key, value);
            addNode(newNode);
            mp[key] = head->next;
        }
        else if(cap == mp.size()) {
            cout<<key<<" ";
            cout<<tail->prev->key<<endl;
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
            node * newNode = new node(key, value);
            addNode(newNode);
            mp[key] = head->next;
        }
        else {
            node * newNode = new node(key, value);
            addNode(newNode);
            mp[key] = head->next;
        }
    }
};
  

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
