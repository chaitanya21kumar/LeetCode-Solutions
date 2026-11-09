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
    int s=0;
    void f(TreeNode* root,int l, int h){
        if(root->left) f(root->left,l,h);
        int x=root->val;
        if(x>=l && x<=h) s+=x;
        if(root->right) f(root->right,l,h);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {

        f(root,low,high);
        return s;
        
    }
};