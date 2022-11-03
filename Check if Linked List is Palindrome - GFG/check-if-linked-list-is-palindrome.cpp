//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
   Node * reverse(Node* head){
        Node* prev=NULL,* curr=head,*nextnode;
        while(curr!=NULL){
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here  1 2 3 4 5 6
        Node * s=head;
        Node* f=head;
        while(s && f && f->next){
          s=s->next;
          f=f->next->next;
        }
        Node * res;
        if(f==NULL) res=reverse(s);
        else res=reverse(s->next);
        while(res!=NULL){
            if(head->data!=res->data) return 0;
            head=head->next;
            res=res->next;
        }
        return 1;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends