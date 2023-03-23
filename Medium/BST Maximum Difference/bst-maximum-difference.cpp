//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++
#define ll long long int

class Solution{
public:
    int maxDifferenceBST(Node *root,int target){
        // Code here
         ll sum= 0;
        while(root!=NULL){
            
            if(root->data==target){
                break;
            }
            
            else if(root->data>target){
                sum+=root->data;
                root= root->left;
            } else {
                sum+=root->data;
                root= root->right;
            }
        }
        
        if(root==NULL){
            return -1;
        }
       
        if(!root->left && !root->right)
            return sum;
        
        ll ans= INT_MIN;
        queue<pair<Node*,ll>>q;
        if(root->left)
            q.push({root->left,root->left->data});
        if(root->right)
            q.push({root->right,root->right->data});
            
        while(!q.empty()){
            
            Node* front= q.front().first;
            ll data= q.front().second;
            q.pop();
            
            if(front->left==NULL && front->right==NULL){
                ans= max(ans,sum-data);
            }
            
            if(front->left){
                q.push({front->left,data+front->left->data});
            }
            
            if(front->right){
                q.push({front->right,data+front->right->data});
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends