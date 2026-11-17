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
    unordered_map<int,vector<TreeNode*>> m;
    vector<TreeNode*> f(int n){
        if(n%2==0){
            return {};
        }
        if(n==1){
            TreeNode* root=new TreeNode(0);
            return {root};
        }
        if(m.find(n)!=m.end()) return m[n];
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> l=f(i);
            vector<TreeNode*> r=f(n-i-1);
            for(auto &x:l){
                for(auto &y:r){
                    TreeNode* root=new TreeNode(0);
                    root->left=x;
                    root->right=y;
                    ans.push_back(root);
                }
            }
        }
        return m[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {

        return f(n);
        
    }
};