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
    int n;
    TreeNode* f(int &i,int d,string s){

        if(i>=n) return NULL;
        int j=i;
        while(j<n && s[j]=='-') j++;
        int dash=j-i;
        if(d!=dash) return NULL;
        int num=0;
        i+=dash;
        while(i<n && s[i]!='-'){
            num*=10;
            num+=(s[i]-'0');
            i++;
        }
        TreeNode* root=new TreeNode(num);
        root->left=f(i,d+1,s);
        root->right=f(i,d+1,s);
        return root;
 
    }
    TreeNode* recoverFromPreorder(string traversal) {

        n=traversal.size();
        int i=0;
        return f(i,0,traversal);
        
    }
};