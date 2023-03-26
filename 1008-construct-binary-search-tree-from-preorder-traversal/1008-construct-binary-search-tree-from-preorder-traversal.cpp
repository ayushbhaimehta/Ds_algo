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
    
    TreeNode* f(vector<int>&arr,int &i,int r){
        if(i==arr.size() || arr[i]>r) return NULL;
        
      
        TreeNode* curr= new TreeNode(arr[i]);
        i++;
        curr->left=f(arr,i,curr->val);
        curr->right=f(arr,i,r);
  
        return curr;
    }
    
    TreeNode* bstFromPreorder(vector<int>& arr) {
        int i=0;
        return f(arr,i,INT_MAX);
    }
};