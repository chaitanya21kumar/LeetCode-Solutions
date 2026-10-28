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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* t1=head;
        ListNode* t2=head->next;
        int s=0;
        while(t2!=NULL){
            while(t2->val!=0){
                s+=t2->val;
                t2=t2->next;
            }
            t1->val=s;
            s=0;
            if(t2->next==NULL){
                t1->next=NULL;
                break;
            }
            else{
                t1->next=t2;
                t1=t2;
            }
            t2=t2->next;
        }
        return head;
        
    }
};