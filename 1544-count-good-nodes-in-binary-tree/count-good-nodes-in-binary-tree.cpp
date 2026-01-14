/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int c=0;
    void f(TreeNode* root,int mx){
        if(!root) return;
        if(root->val>=mx){
            c++;
            mx=max(mx,root->val);
        }
        if(root->left) f(root->left,mx);
        if(root->right) f(root->right,mx);

    }
    int goodNodes(TreeNode* root) {

        int mx=INT_MIN;
        f(root,mx);
        return c;
        
    }
};