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
    TreeNode* reverseOddLevels(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> v;
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(lvl%2==1){
                int i=0,j=v.size()-1;
                while(i<j){
                    int x=v[i]->val;
                    v[i]->val=v[j]->val;
                    v[j]->val=x;
                    i++;j--;
                }
            }
            lvl++;
        }
        return root;
        
    }
};