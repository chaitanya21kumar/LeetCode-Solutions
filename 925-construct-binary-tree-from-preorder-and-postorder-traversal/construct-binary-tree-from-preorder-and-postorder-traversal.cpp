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
    TreeNode* f(vector<int>& prev,int prs,int pre,vector<int>& postv,int ps,int pe){
        if(ps>pe) return NULL;
        TreeNode* root=new TreeNode(prev[prs]);
        if(prs==pre) return root;
        int psidx=m[prev[prs+1]];
        int len=psidx-ps+1;
        root->left=f(prev,prs+1,prs+len,postv,ps,psidx);
        root->right=f(prev,prs+len+1,pre,postv,psidx+1,pe-1);
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