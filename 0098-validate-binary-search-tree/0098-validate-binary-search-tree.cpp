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
    
    bool f(TreeNode* root,long l,long r){
        if(root==NULL) return true;
        if(root->val>=r || root->val<=l) return false;
        
        return (f(root->left,l,root->val) && f(root->right,root->val,r));
    }
    
    bool isValidBST(TreeNode* root) {
        return f(root,LONG_MIN, LONG_MAX);
    }
};