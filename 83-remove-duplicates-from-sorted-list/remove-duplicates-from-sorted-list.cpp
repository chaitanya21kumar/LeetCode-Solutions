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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev=head;
        ListNode* temp=head;
        while(temp){
            if(prev->val==temp->val) temp=temp->next;
            else if(prev->val!=temp->val){
                prev->next=temp;
                prev=temp;
            }
        }
        if(prev) prev->next=NULL;
        return head;  

    }
};