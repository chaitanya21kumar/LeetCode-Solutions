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
    Node* copyRandomList(Node* head) {

        Node* temp=head;
        // inserting copies in bw
        while(temp){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=copy->next;
        }

        // random pointers fix 

        temp=head;
        while(temp){
            Node* copy=temp->next;
            Node* temp_random=temp->random;
            if(temp_random!=NULL) copy->random=temp_random->next;
            else copy->random=NULL;
            temp=temp->next->next;
        }

        Node* dummy=new Node(-1);
        Node* copyhead=dummy;
        
        temp=head;

        while(temp){
            dummy->next=temp->next;
            dummy=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }

        return copyhead->next;

        



        
    }
};