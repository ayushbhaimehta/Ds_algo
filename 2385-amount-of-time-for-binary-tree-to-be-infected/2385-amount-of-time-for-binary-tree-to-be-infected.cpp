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
    
    private:
    TreeNode* f(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode* root,int target){
        if(root==NULL) return root;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* x;
        // cout<<target<<endl;
        
        while(q.empty()==false){
            TreeNode* curr=q.front();
            q.pop();
            // cout<<curr->val<<" "<<endl;
            if(curr!=NULL && curr->val==target){
                x=curr;
                // cout<<"halla bol"<<endl;
            }
            
            if(curr->left){
                q.push(curr->left);
                parent[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent[curr->right]=curr;
            }
        }
        return x;
    }
    
public:
    unordered_map<int,vector<int>> v;  //adjacency list

//create undirected graph for every parent-child  --> DFS
void createGraph(TreeNode* root,int parent=-1){
    if(!root) return;
    int value= root->val;
    if(parent!=-1){
        v[parent].push_back(value);
        v[value].push_back(parent);
    }
    createGraph(root->left, value);
    createGraph(root->right, value);
}

int amountOfTime(TreeNode* root, int start) {
    //create graph of given tree
    createGraph(root);

    //start bfs
    queue<int> q;
    unordered_map<int,bool> seen;
    q.push(start);
    seen[start]=true;
    int time=0;
    for(;q.size();time++){
        int n= q.size();
        while(n--){
            auto node= q.front();  q.pop();
            for(auto i:v[node]){
                if(!seen[i]){
                    q.push(i);
                    seen[i]=true;
                }
            }
        }
    }
    return time-1;
}
};