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
        if(root==l || root==r) return root;
        if(l==NULL) return r;
        if(r==NULL) return l;
        if(root!=NULL && root->val<l->val && root->val<r->val){
            return lowestCommonAncestor(root->right,l,r);
        }
        if(root!=NULL && root->val>l->val && root->val>r->val){
            return lowestCommonAncestor(root->left,l,r);
        }
        return root;
    }
};