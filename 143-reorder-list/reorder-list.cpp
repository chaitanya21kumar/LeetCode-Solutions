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
    void reorderList(ListNode* head) {

        ListNode* dummyNode=head;

        vector<int> v;

        ListNode* cur=head;

        while(cur){
            v.push_back(cur->val);
            cur=cur->next;
        }

        int n=v.size();
        int x=n;
        if(x%2==0) x--;
        if(n==1) return;

        for(int i=0;i<=x/2;i++){
            int l=i,r=n-i-1;
            ListNode* left=new ListNode(v[l]);
            ListNode* right=new ListNode(v[r]);
            if(l==r){
                dummyNode->next=right;
                right->next=NULL;
                break;
            }
            if(dummyNode==head){
                dummyNode->next=right;
                dummyNode=right;
            }
            else{
                dummyNode->next=left;
                left->next=right;
                dummyNode=right;
            }
            
        }


        
    }
};