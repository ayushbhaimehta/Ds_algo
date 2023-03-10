//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool f(int mid,int arr[], int n, int M){
        int count=0,sum=0;
        for(int i=0;i<n;i++){
            if (sum + arr[i] > mid) {
                count++;
                sum = arr[i];
                if (sum > mid) return false;
            } 
            else {
              sum += arr[i];
            }
        }
        if(count<M) return true;
        return false;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int M) 
    {
        //code here
        if(n<M) return -1;
        int psum=0,mini=INT_MAX,ans=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,arr[i]);
            psum+=arr[i];
        }
        
        int low=mini,high=psum;
        
        while(low<=high){
            int mid= (low+high)/2;
            
            if(f(mid,arr,n,M)==true){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends