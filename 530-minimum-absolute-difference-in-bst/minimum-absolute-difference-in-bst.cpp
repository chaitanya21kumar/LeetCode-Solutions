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
    int min_diff = 1e9;
    int prev_value = -1;
    
    void inOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        
        inOrderTraversal(node->left);
        
        if (prev_value != -1) {
            min_diff = min(min_diff, node->val - prev_value);
        }
        
        prev_value = node->val;
        
        inOrderTraversal(node->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inOrderTraversal(root);
        return min_diff;
    }
};