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
    int sum=0;
    void f(TreeNode* root){
        if(!root) return;
        if(root->left) f(root->left);
        if(root->right) f(root->right);
        sum+=root->val;
    }
    void f1(TreeNode* root){
        if(!root) return;
        if(root->left) f1(root->left);
        int x=root->val;
        root->val=sum;
        sum-=x;
        if(root->right) f1(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        f(root);
        f1(root);
        return root;
    }
};