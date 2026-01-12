class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* next=NULL;
        Node* prev=NULL;
        Node(int k,int v){
            key=k;
            val=v;
        }
    };

    int cap;
    map<int,Node*> m;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap=capacity;
        m.clear();
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void deleteNode(Node* node){
        Node* nextnode=node->next;
        Node* prevnode=node->prev;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }

    void insertAfterHead(Node* node){
        Node* afterhead=head->next;
        head->next=node;
        afterhead->prev=node;
        node->next=afterhead;
        node->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        Node* node=m[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* node=m[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(m.size()==cap){
                Node* lru=tail->prev;
                m.erase(lru->key);
                deleteNode(lru);
            }
            Node* node=new Node(key,value);
            m[key]=node;
            insertAfterHead(node);
        }



        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */