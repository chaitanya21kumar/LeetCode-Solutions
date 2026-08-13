class LRUCache {
public:
    struct Node{
        int key;
        int value;

        Node* prev;
        Node* next;

        Node(int k,int v){
            key=k;
            value=v;
            prev=NULL;
            next=NULL;
        }

    };

    int cap;
    unordered_map<int,Node*> m;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void addNode(Node* node){
        Node* firstNode=head->next;
        head->next=node;
        node->next=firstNode;
        node->prev=head;
        firstNode->prev=node;
    }

    void deleteNode(Node* node){
        Node* nextNode=node->next;
        Node* prevNode=node->prev;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    int get(int key) {
        
        if(m.find(key)==m.end()) return -1;
        Node* node=m[key];
        deleteNode(node);
        addNode(node);
        return node->value;
        
    }
    
    void put(int key, int value) {

        if(m.find(key)!=m.end()){
            m[key]->value=value;
            deleteNode(m[key]);
            addNode(m[key]);
            return;
        }

        if(m.size()==cap){
            Node* lastNode=tail->prev;
            m.erase(lastNode->key);
            deleteNode(lastNode);
        }

        Node* node=new Node(key,value);
        addNode(node);
        m[key]=node;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */