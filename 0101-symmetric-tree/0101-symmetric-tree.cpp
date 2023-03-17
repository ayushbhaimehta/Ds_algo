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
    bool f(TreeNode *Left,TreeNode *Right){
        if(Left==NULL || Right==NULL){
            return (Left==Right);
        }
        
        return (Left->val==Right->val && f(Left->left,Right->right) && f(Left->right,Right->left));
    }
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        return f(root->left,root->right);
    }
};