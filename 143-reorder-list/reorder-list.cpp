/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* cur=head;
        while(cur){
            ListNode* nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* head2=reverseLL(slow->next); // head2 is reversed head
        slow->next=NULL;

        ListNode* left=head;
        ListNode* right=head2;
        ListNode* dummy=head;
        


        while(left && right){
            if(dummy==head){

            }
            else{
                dummy->next=left;
            }
            ListNode* ln=left->next;
            ListNode* rn=right->next;
            left->next=right;
            dummy=right;
            left=ln;
            right=rn;
            // 1 2 3 | 4 5
            // 1 5| 2 4 | 3 


        }

        if(left!=NULL){
            dummy->next=left;
        }
        
    }
};