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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        Postorder(root,ans);
        return ans;
    }
    
    private:
    void Postorder (TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        Postorder (root -> left, nodes);
        Postorder (root -> right, nodes);
        nodes.push_back(root -> val);
    }
};