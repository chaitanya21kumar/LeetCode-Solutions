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
    ListNode* f(ListNode* temp,int k){
        k--;
        while(k-- && temp){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseLL(ListNode* temp){
        ListNode* prev=NULL;
        ListNode* cur=temp;
        while(cur){
            ListNode* nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp=head;
        ListNode* prev=NULL;

        while(temp){
            ListNode* kthnode=f(temp,k);
            if(kthnode==NULL){
                if(prev!=NULL){
                    prev->next=temp;
                }
                break;
            }
            else{
                ListNode* nextnode=kthnode->next;
                kthnode->next=NULL;
                reverseLL(temp);
                if(temp==head) head=kthnode;
                else{
                    if(prev){
                        prev->next=kthnode;
                    }
                }
                prev=temp;
                temp=nextnode;
            }
        }
        return head;


        
    }
};