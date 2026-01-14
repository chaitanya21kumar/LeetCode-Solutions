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
    int ans=0;
    bool f(TreeNode* root,int &k){
        if(!root) return false;
        if(f(root->left,k)) return true;
        k--;
        if(k==0){
            ans=root->val;
            return true;
        }
        if(f(root->right,k)) return true;
        return false;
    }
    int kthSmallest(TreeNode* root, int k) {
        f(root,k);
        return ans;
    }
};