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
    TreeNode* f(vector<int> &preorder,int ps,int pe,vector<int> &inorder,int is,int ie){
        if(ps>pe || is>ie) return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int i=m[preorder[ps]];
        int x=i-is;
        root->left=f(preorder,ps+1,ps+x,inorder,is,i-1);
        root->right=f(preorder,ps+x+1,pe,inorder,i+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n=inorder.size();
        for(int i=0;i<n;i++) m[inorder[i]]=i;

        TreeNode* root=f(preorder,0,n-1,inorder,0,n-1);
        return root;

        
    }
};