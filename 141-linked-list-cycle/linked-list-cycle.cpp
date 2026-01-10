/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || head->next==NULL) return false;
        ListNode* move1=head;
        ListNode* move2=head;

        while(move1 && move2){
            move1=move1->next;
            if(move2->next==NULL) return false;
            else move2=move2->next->next;
            if(move1==move2) return true;
        }

        return false;
        
    }
};