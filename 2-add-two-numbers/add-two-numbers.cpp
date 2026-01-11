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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        int c=0;
        while(l1 || l2){
            int s=c;
            if(l1) s+=(l1->val);
            if(l2) s+=(l2->val);
            ListNode* node=new ListNode(s%10);
            cur->next=node;
            cur=cur->next;
            if(s>9) c=1;
            else c=0;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }

        if(c){
            ListNode* node=new ListNode(1);
            cur->next=node;
        }

        return dummy->next;


        
    }
};