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
    
    int maxSum(TreeNode* root, int& ans) {
    //Base Case
    if(root == NULL){
        return 0;
    }
    int leftBS = root->val + maxSum( root->left , ans );
    int rightBS = root->val + maxSum( root->right , ans );
    
    ans = max({
                ans,           
                root->val,      
                leftBS,         
                rightBS,        
                leftBS + rightBS - root->val   
                                              
            });
    
    return max({ leftBS , rightBS , root->val });
}

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    maxSum(root, ans);
    return ans;
}
};