/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> m;
    Node* copyRandomList(Node* head) {

        Node* temp=head;
        while(temp){
            Node* node=new Node(temp->val);
            m[temp]=node;
            temp=temp->next;
        }

        temp=head;
        while(temp){
            Node* nxt=temp->next;
            Node* rndm=temp->random;

            m[temp]->next=m[nxt];
            m[temp]->random=m[rndm];
            temp=temp->next;
        }

        return m[head];



        
    }
};