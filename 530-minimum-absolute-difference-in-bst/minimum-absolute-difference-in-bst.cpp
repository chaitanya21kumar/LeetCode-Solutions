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
    int ans=INT_MAX;
    int prev=INT_MAX;
    void f(TreeNode* root){
        if(root->left) f(root->left);
        if(prev!=INT_MAX){
            ans=min(ans,root->val-prev);
        }
        prev=root->val;
        if(root->right) f(root->right);
    }
    int getMinimumDifference(TreeNode* root) {

        f(root);
        return ans;
        
    }
};