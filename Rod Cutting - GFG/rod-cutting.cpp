//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  int f(int i,int length,int arr[],vector<vector<int>>&dp){
      if(i==0){
          if(i+1<=length){
              return length*arr[0];
          }
          return 0;
      }
      
      if(dp[i][length]!=-1) return dp[i][length];
      
      int notTake=f(i-1,length,arr,dp);
      int take=INT_MIN;
      if(i+1<=length){
          take=arr[i]+f(i,length-(i+1),arr,dp);
      }
      
      return dp[i][length]=max(take,notTake);
  }
  
    int cutRod(int arr[], int n) {
        //code here
        if(n==0) return 0;
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int length=0;length<=n;length++){
            dp[0][length]=length*arr[0];
        }
        
        for(int i=1;i<n;i++){
            for(int length=0;length<=n;length++){
                int notTake=dp[i-1][length];
                int take=INT_MIN;
                if(i+1<=length){
                    take=arr[i]+dp[i][length-(i+1)];
                }
      
                dp[i][length]=max(take,notTake);
            }
        }
        
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends