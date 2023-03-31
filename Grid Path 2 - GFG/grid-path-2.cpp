//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int f(int i,int j,vector<vector<int>>& arr,vector<vector<int>>&dp,int mod){
      if(i==0 && j==0 && arr[i][j]!=1) return 1;
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      int up=0,left=0;
      if(i>0 && arr[i][j]!=1) up=f(i-1,j,arr,dp,mod)%mod;
      if(j>0 && arr[i][j]!=1) left=f(i,j-1,arr,dp,mod)%mod;
      
      return dp[i][j]=(left+up)%mod;
  }
  
    int totalWays(int n, int m, vector<vector<int>>& arr) {
        // Code here
        int mod=1e9+7;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,arr,dp,mod);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends