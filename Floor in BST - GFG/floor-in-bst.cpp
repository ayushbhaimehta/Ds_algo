//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

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

int floor(Node *root, int x);

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

        int s;
        cin >> s;

        cout << floor(root, s) << "\n";
    }
}

// } Driver Code Ends


// Function to search a node in BST.

int floor(Node* root, int x) {
    // Code here
    if(root==NULL) return -1;
    int maxi=INT_MIN;
    Node* curr=root;
    while(curr!=NULL){
        
        if(curr->data>x){
            curr=curr->left;
        }
        else if(curr->data<x){
            maxi=max(maxi,curr->data);
            curr=curr->right;
        }
        else{
            return x;
        }
    }
    if(maxi==INT_MIN) return -1;
    return maxi;
}
