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
    vector<TreeNode*> f(int s,int e){
        vector<TreeNode*> ans;

        if(s>e){
            ans.push_back(NULL);
            return ans;
        }

        for(int i=s;i<=e;i++){
            vector<TreeNode*> ls=f(s,i-1);
            vector<TreeNode*> rs=f(i+1,e);

            for(auto &x:ls){
                for(auto &y:rs){
                    TreeNode* root=new TreeNode(i);
                    root->left=x;
                    root->right=y;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {

        return f(1,n);
        
    }
};