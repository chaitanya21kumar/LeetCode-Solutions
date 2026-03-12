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
    ListNode* removeElements(ListNode* head, int val) {

        vector<int> v;
        ListNode* temp=head;
        while(temp){
            if(temp->val!=val) v.push_back(temp->val);
            temp=temp->next;
        }

        ListNode* dummy=new ListNode(-1);
        temp=dummy;
        for(int i=0;i<v.size();i++){
            ListNode* node=new ListNode(v[i]);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;

        
    }
};