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
    int f(vector<int> &v,int n){

        int swps=0;
        vector<int> sv(v.begin(),v.end());
        sort(sv.begin(),sv.end());
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[v[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(v[i]!=sv[i]){
                int idx=m[sv[i]];
                m[v[i]]=idx;
                m[sv[i]]=i;
                swap(v[i],v[idx]);
                swps++;
            }
        }
        return swps;

    }
    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans+=f(v,n);
        }
        return ans;

    }
};