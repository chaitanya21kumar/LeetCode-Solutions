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
    int f(TreeNode* root){
        if(!root) return 0;
        int ans=0;
        ans=1+max(f(root->left),f(root->right));
        return ans;
    }
    int maxDepth(TreeNode* root) {

        return f(root);
        
    }
};