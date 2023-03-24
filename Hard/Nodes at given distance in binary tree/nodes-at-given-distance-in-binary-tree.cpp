//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    vector<Node*> ans;
    Node *t = NULL;
    Node* giveans(Node *root,int target){
        if(!root)return 0;
        if(root->data == target){
            t = root;
            return root;
        }
        Node *left = giveans(root->left,target);
        Node *right = giveans(root->right,target);
        
        if(left || right){
            ans.push_back(root);
        }
        if(left){
            return left;
        }
        if(right){
            return right;
        }
        return NULL;
    }
    vector<int>ans1;
    void give(Node *root,int h,int l){
        if(!root)return;
        
        if(h==l){
            ans1.push_back(root->data);
            return;
        }
        give(root->left,h,l+1);
        give(root->right,h,l+1);
        
    }
    void rev(Node *root){
        
        for(int i=0;i<ans.size();i++){
            if(root->left == NULL){
                root->left = ans[i];
            }else{
                root->right = ans[i];
            }
            if(ans[i]->left == root)ans[i]->left = 0;
            else ans[i]->right = 0;
            root = ans[i];
        }
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {   
        ans.clear();
        t = NULL;
        ans1.clear();
        giveans(root,target);
        give(t,k,0);
        t->left = NULL;
        t->right = NULL;
        rev(t);
        give(t,k,0);
        
        sort(ans1.begin(),ans1.end());
        return ans1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends