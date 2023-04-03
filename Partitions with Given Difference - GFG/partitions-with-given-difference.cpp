//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod =(int)1e9+7;

  int f(int i,int k,vector<int>&arr,vector<vector<int>>&dp){
        if(i == 0){
            if(k==0 && arr[0]==0)
                return 2;
            if(k==0 || k == arr[0])
                return 1;
            return 0;
        }
      
      if(dp[i][k]!=-1) return dp[i][k];
      
      int notTake=f(i-1,k,arr,dp);
      int take=0;
      if(arr[i]<=k) take=f(i-1,k-arr[i],arr,dp);
      
      return dp[i][k]=(take+notTake)%mod;
  }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum-d<0) return 0;
        if((sum-d)%2==1) return 0;
    
        int s1 = (sum-d)/2;
        vector<vector<int>>dp(n,vector<int>(s1+1,-1));
        return f(n-1,s1,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends