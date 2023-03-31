//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int f(vector<vector<int>>&arr,int i,int prev,vector<vector<int>>&dp){
      if(i==0){
          // base condition
          int maxi=0;
          for(int j=0;j<3;j++){
              if(j!=prev){
                  maxi=max(maxi,arr[0][j]);
              }
          }
          return maxi;
      }
      
      if(dp[i][prev]!=-1) return dp[i][prev];
      
      int maxi=0;
      for(int j=0;j<3;j++){
          if(j!=prev){
              maxi=max(maxi,arr[i][j]+f(arr,i-1,j,dp));
          }
      }
      
      return dp[i][prev]=maxi;
  }
  
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(arr,n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends