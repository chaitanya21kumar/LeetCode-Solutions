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
    int f1(TreeNode* root){
        if(!root) return 0;
        int lh=1+f1(root->left);
        int rh=1+f1(root->right);

        return max(lh,rh);
    }
    bool f(TreeNode* root){
        if(!root) return true;
        int lh=f1(root->left);
        int rh=f1(root->right);
        if(abs(rh-lh)>1) return false;
        return f(root->left) && f(root->right);
    }
    bool isBalanced(TreeNode* root) {

        return f(root);
        
    }
};