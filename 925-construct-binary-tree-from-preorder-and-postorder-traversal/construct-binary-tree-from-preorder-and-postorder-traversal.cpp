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
    TreeNode* f(vector<int>& preorder,int prs,int pre,vector<int>& postorder,int ps,int pe){
        if(prs>pre) return NULL;
        TreeNode* root=new TreeNode(preorder[prs]);
        if(ps==pe) return root;
        int psidx=m[preorder[prs+1]];
        int len=psidx-ps+1;
        root->left=f(preorder,prs+1,prs+len,postorder,ps,psidx);
        root->right=f(preorder,prs+len+1,pre,postorder,psidx+1,pe-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        int n=preorder.size();
        for(int i=0;i<n;i++){
            m[postorder[i]]=i;
        }
        return f(preorder,0,n-1,postorder,0,n-1);
        
    }
};