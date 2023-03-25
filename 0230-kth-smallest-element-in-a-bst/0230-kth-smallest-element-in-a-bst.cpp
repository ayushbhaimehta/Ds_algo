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
    
      void f(int &ans,TreeNode* root,int &k){
      if(root==NULL) return;
      
      f(ans,root->left,k);
      k--;
      if(k==0){
          ans=root->val;
      }
      f(ans,root->right,k);
  }
    
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        int ans=-1;
        f(ans,root,k);
        return ans;
    }
};