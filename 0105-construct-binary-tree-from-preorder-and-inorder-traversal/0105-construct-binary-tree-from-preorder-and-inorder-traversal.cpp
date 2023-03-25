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
    
    TreeNode* f(vector<int>&in,vector<int>&pre,int preStart,int inStart,int preEnd,int inEnd,unordered_map<int,int>&map){
        if(preEnd<preStart || inEnd<inStart) return NULL; // case when there is nothing in inorder and preorder vector
        
        // i->prestart j->instart p->preend il->inend
        TreeNode* curr= new TreeNode(pre[preStart]);
        int ind=map[curr->val];
        int numleft=ind-inStart;
        
        curr->left=f(in,pre,preStart+1,inStart,preStart+numleft,ind-1,map);
        curr->right=f(in,pre,preStart+numleft+1,ind+1,preEnd,inEnd,map);
        
        return curr;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=in.size();
        // step 1 hash all inorder values
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[in[i]]=i;
        }
        
        // step 2 find the preorder number in inorder
        TreeNode* root=f(in,pre,0,0,n-1,n-1,map);
        return root;
    }
};