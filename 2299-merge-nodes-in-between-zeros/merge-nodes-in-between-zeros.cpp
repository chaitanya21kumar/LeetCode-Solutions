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

        vector<int> v;
        ListNode* temp=head;
        int s=0;
        while(temp!=NULL){
            if(temp->val==0){
                if(s!=0){
                    v.push_back(s);
                }
                s=0;
            }
            else s+=temp->val;
            temp=temp->next;
        }
        ListNode* h1=new ListNode(0);
        ListNode* h2=h1;
        for(int i=0;i<v.size();i++){
            h2->next=new ListNode(v[i]);
            h2=h2->next;
        }
        return h1->next;
        
    }
};