/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* l, TreeNode* r) {
        if(root==NULL || root==l || root==r) return root;
        
        TreeNode* left= lowestCommonAncestor(root->left,l,r);
        TreeNode* right=lowestCommonAncestor(root->right,l,r);
        
        if(left==NULL) return right;
        else if(right==NULL) return left;
        return root;
    }
};