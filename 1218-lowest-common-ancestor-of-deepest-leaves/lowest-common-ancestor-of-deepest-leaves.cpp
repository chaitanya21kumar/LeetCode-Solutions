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
    unordered_map<TreeNode*,int> m;
    int mxd=0;
    void f1(TreeNode* root,int d){
        if(!root) return;
        m[root]=d;
        mxd=max(mxd,d);
        f1(root->left,d+1);
        f1(root->right,d+1);
    }

    TreeNode* f2(TreeNode* root){
        if(!root || m[root]==mxd) return root;
        TreeNode* left=f2(root->left);
        TreeNode* right=f2(root->right);
        if(left==NULL && right==NULL) return NULL;
        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        f1(root,0);
        return f2(root);
        
    }
};