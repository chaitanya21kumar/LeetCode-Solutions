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
    void f(TreeNode* root,int d){

        if(!root->left && !root->right){
            ans=min(ans,d);
            return;
        }
        if(root->left){
            f(root->left,d+1);
        }
        if(root->right){
            f(root->right,d+1);
        }
        
    }
    int minDepth(TreeNode* root) {

        if(!root) return 0;
        f(root,1);
        return ans;
        
    }
};