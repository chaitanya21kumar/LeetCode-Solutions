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
    int level[200000];
    int height[200000];
    int levelMxHeight[200000];
    int levelSecondMxHeight[200000];
    int findHeight(TreeNode* root,int l){
        if(!root) return 0;
        level[root->val]=l;
        height[root->val]=1+max(findHeight(root->left,l+1),findHeight(root->right,l+1));
        if(levelMxHeight[l]<height[root->val]){
            levelSecondMxHeight[l]=levelMxHeight[l];
            levelMxHeight[l]=height[root->val];
        }
        else if(levelSecondMxHeight[l]<height[root->val]){
            levelSecondMxHeight[l]=height[root->val];
        }
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        int m=queries.size();
        findHeight(root,0);
        vector<int> ans;
        for(int i=0;i<m;i++){
            int L=level[queries[i]];
            int x=height[queries[i]];
            int H=x;
            if(x==levelMxHeight[L]){
                H=levelSecondMxHeight[L];
            }
            else{
                H=levelMxHeight[L];
            }
            ans.push_back(L+H-1);
        }
        return ans;

        
    }
};