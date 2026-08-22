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
    vector<int> v;
    void f(TreeNode* root){
        if(root->left) f(root->left);
        v.push_back(root->val);
        if(root->right) f(root->right);
    }
    int minDiffInBST(TreeNode* root) {

        f(root);
        int ans=INT_MAX;
        for(int i=0;i<=v.size()-2;i++){
            ans=min(ans,abs(v[i]-v[i+1]));
        }
        return ans;

    }
};