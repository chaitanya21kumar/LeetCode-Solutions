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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if(head==NULL || head->next==NULL || head->next->next==NULL) return {-1,-1};
        ListNode* prev=head;
        ListNode* cur=head->next;
        int fci=-1;
        int pci=-1;
        int ci=1;
        int mnd=INT_MAX;
        while(cur->next!=NULL){
            if( (cur->val>prev->val && cur->val>cur->next->val) || (cur->val<prev->val && cur->val<cur->next->val) ){
                if(fci==-1){
                    fci=ci;
                }
                else{
                    mnd=min(mnd,ci-pci);
                }
                pci=ci;
            }
            prev=cur;
            cur=cur->next;
            ci++;
        }
        if(mnd==INT_MAX) return {-1,-1};
        return {mnd,pci-fci};

        
    }
};