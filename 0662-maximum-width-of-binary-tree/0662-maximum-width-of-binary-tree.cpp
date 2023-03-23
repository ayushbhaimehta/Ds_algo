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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        while(q.empty()==false){
            int n=q.size();
            int index=q.front().second;
            int first,last;
            
            for(int i=0;i<n;i++){
                int curr_id=q.front().second-index;
                TreeNode* curr=q.front().first;
                q.pop();
                if(i==0) first=curr_id;
                if(i==n-1) last=curr_id;
                
                if(curr->left) q.push({curr->left,(long long)2*curr_id+1});
                if(curr->right) q.push({curr->right,(long long)2*curr_id+2});
            }
            
            ans=max(ans,last-first+1);
        }
        
        return ans;
    }
};