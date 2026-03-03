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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* temp=head;
        while(temp){
            if(temp->next){
                ListNode* node=new ListNode(gcd(temp->val,temp->next->val));
                ListNode* next=temp->next;
                temp->next=node;
                node->next=next;
                temp=node->next;
            }
            else break;
        }
        return head;
        
    }
};