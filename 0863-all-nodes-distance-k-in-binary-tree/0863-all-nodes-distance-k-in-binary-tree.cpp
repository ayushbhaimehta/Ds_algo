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
   
    void levelorder(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode* root){
    if(root==NULL) return;
    queue<TreeNode*>q;
    q.push(root);
    
    while(q.empty()==false){
        TreeNode* curr=q.front();
        q.pop();
        
        if(curr->left){
            parent[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right]=curr;
            q.push(curr->right);
        }
    }
    
    return;
}

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        levelorder(parent,root);
        
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=1;
        // cout<<t->data<<endl;            
        int count=0;
        
        while(q.empty()==false){
            if(count==k) break;
            count++;
            
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                
                if(curr->left && visited[curr->left]==0){
                    q.push(curr->left);
                    visited[curr->left]=1;
                }
                
                if(curr->right && visited[curr->right]==0){
                    q.push(curr->right);
                    visited[curr->right]=1;
                }
                
                if(parent[curr] && visited[parent[curr]]==0){
                    q.push(parent[curr]);
                    visited[parent[curr]]=1;
                }
            }
        }
        
        vector<int>ans;
        while(q.empty()==false){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};