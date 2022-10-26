//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int rc=0,bc=0,gc=0;
        for(int i=0;i<n;i++){
            if(a[i]=='R') rc++;
            if(a[i]=='B') bc++;
            if(a[i]=='G') gc++;
        }
        if(bc==0 && gc==0) return n;
        if(gc==0 && rc==0) return n;
        if(bc==0 && rc==0) return n;
        
        if((bc%2==0 && rc%2==0 && gc%2==0) || (bc%2==1 && rc%2==1 && gc%2==1))
            return 2;
        
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends