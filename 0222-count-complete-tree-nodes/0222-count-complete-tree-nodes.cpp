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
    int findl(TreeNode* root){
        if(root==NULL) return 0;
        
        TreeNode* curr=root;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->left;
        }
        return count;
    }
    
    int findr(TreeNode* root){
        if(root==NULL) return 0;
        
        TreeNode* curr=root;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh=findl(root);
        int rh=findr(root);
        
        if(lh==rh) return (pow(2,lh)-1);
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};