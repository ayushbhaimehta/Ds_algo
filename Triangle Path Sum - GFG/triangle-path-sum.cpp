//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int f(int i,int j, vector<vector<int>>& arr,vector<vector<int>>&dp,int n){

      
      //base conditions
  if(i==n-1) return arr[i][j];
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      int right=arr[i][j]+f(i+1,j+1,arr,dp,n);
      int down =arr[i][j]+f(i+1,j  ,arr,dp,n);
      
      return dp[i][j]=min(right,down);
  }

  
    int minimizeSum(int n, vector<vector<int>>& arr) {
        // Code here
        vector<vector<int> > dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=arr[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<i+1;j++){
                int right=arr[i][j]+dp[i+1][j+1];
                int down =arr[i][j]+dp[i+1][j];
      
                dp[i][j]=min(right,down);
            }
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends