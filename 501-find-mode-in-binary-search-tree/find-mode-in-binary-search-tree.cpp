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
    unordered_map<int,int> m;
    int mx=0;
    void f(TreeNode* root){
        if(!root) return;
        if(root->left) f(root->left);
        m[root->val]++;
        mx=max(mx,m[root->val]);
        if(root->right) f(root->right);
    }
    vector<int> findMode(TreeNode* root) {

        f(root);
        vector<int> ans;
        for(auto &x:m){
            if(x.second==mx){
                ans.push_back(x.first);
            }
        }
        return ans;
        
    }
};