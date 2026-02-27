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
    int mn=INT_MAX;
    void f(TreeNode* root,int d){
        if(!root) return;
        if(!root->left && !root->right) mn=min(mn,d);
        f(root->left,d+1);
        f(root->right,d+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        f(root,1);
        return mn;
        
    }
};