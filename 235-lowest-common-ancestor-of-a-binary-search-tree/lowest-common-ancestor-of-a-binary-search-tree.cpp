/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* temp=root;
        int pv=p->val,qv=q->val;
        if(pv>=qv){
            int x=qv;
            qv=pv;
            pv=x;
        }
        while(temp){
            int cv=temp->val;
            if(cv<pv && cv<qv) temp=temp->right;
            else if(pv<cv && qv<cv) temp=temp->left;
            else break;
        }
        return temp;
        
    }
};