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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        typedef pair<int,ListNode*> p;
        priority_queue<p,vector<p>,greater<p>> pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL) pq.push({lists[i]->val,lists[i]});
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(!pq.empty()){
            ListNode* node=pq.top().second;
            pq.pop();
            temp->next=node;
            temp=node;
            if(node->next) pq.push({node->next->val,node->next});
        }

        return dummy->next;

        



        
    }
};