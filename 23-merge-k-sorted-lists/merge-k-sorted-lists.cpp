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
    ListNode* f(ListNode* head1,ListNode* head2){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(head1 && head2){
            if(head1->val<=head2->val){
                temp->next=head1;
                temp=head1;
                head1=head1->next;
            }
            else{
                temp->next=head2;
                temp=head2;
                head2=head2->next;
            }
        }
        if(head1) temp->next=head1;
        if(head2) temp->next=head2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode* head1=lists.back();
            lists.pop_back();
            ListNode* head2=lists.back();
            lists.pop_back();
            ListNode* head=f(head1,head2);
            lists.push_back(head);
        }

        return lists[0];
        
    }
};