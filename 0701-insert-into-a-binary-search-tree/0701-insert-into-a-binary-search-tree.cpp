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
    TreeNode* insertIntoBST(TreeNode* root, int target) {
        TreeNode* x=new TreeNode(target);
        if(root==NULL) return x;
        
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->val<target){
                if(curr->right){
                     curr=curr->right;
                }
                else{
                    curr->right=x;
                    break;
                }
            }
            else{
                if(curr->left){
                     curr=curr->left;
                }
                else{
                    curr->left=x;
                    break;
                }
            }
        }
        return root;
    }
};