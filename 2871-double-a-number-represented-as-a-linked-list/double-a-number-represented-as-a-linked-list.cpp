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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {

        head=reverse(head);
        ListNode* curr=head;
        ListNode* prev=NULL;
        int c=0;
        while(curr!=NULL){
            int s=(curr->val)*2 + c;
            curr->val=s%10;
            c=s/10;
            prev=curr;
            curr=curr->next;
        }
        if(c>0){
            prev->next=new ListNode(c);
        }
        return reverse(head);
        
    }
};