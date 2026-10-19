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
class FindElements {
public:
    unordered_set<int> s;
    void f(TreeNode* root,int v){
        if(!root) return;
        root->val=v;
        s.insert(v);
        if(root->left){
            f(root->left,2*v+1);
        }
        if(root->right){
            f(root->right,2*v+2);
        }
        
    }
    FindElements(TreeNode* root) {

        if(root) f(root,0);
        
    }
    
    bool find(int target) {

        if(s.find(target)!=s.end()) return true;
        return false;
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */