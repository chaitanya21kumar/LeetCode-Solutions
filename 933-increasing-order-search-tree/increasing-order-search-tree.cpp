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
    TreeNode* prev=NULL;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        if(root->left) inorder(root->left);
        root->left=NULL;
        if(prev!=NULL){
            prev->right=root;
        }
        prev=root;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {

        TreeNode* ans=new TreeNode(0);
        prev=ans;
        inorder(root);
        return ans->right;
        
    }
};