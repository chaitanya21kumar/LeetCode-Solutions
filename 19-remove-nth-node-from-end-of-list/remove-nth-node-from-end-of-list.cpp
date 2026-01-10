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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(!head || !head->next) return NULL;
        int len=0;

        ListNode* cur=head;
        while(cur){
            len++;
            cur=cur->next;
        }

        int k=len-n+1;

        int c=0;
        cur=head;

        if(n==len){
            return head->next;
        }

        while(cur){
            c++;
            if(c+1==k){
                cout<<cur->next->val<<endl;
                cur->next=cur->next->next;
                break;
            }
            cur=cur->next;
        }

        return head;






        
    }
};