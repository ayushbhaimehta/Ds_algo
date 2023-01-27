//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        Node *curr=head;
        Node *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            curr=curr->next;
        }
        // corner case for all even numbers
        if(fast->next!=NULL){
            return curr->next->data;
        }
        
        return curr->data;
    }
};


//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}

// } Driver Code Ends