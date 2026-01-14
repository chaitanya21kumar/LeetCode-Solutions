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
    typedef long long int ll;
    bool f(TreeNode* root,ll lb,ll ub){
        if(!root) return true;
        if(root->val>lb && root->val<ub){
            return f(root->left,lb,root->val) && f(root->right,root->val,ub);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        
        ll lb=LLONG_MIN,ub=LLONG_MAX;
        return f(root,lb,ub);
        
    }
};