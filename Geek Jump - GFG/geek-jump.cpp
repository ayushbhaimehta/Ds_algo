//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int minimumEnergyUtill(vector<int>&arr,int i,vector<int>&dp){
      if(i==0){
          // base conditon
          return 0;
      }
      if(i==1){
          return abs(arr[i]-arr[0]);
      }
      
      if(dp[i]!=-1) return dp[i];
      
      int left=abs(arr[i]-arr[i-1])+minimumEnergyUtill(arr,i-1,dp);
      int right=abs(arr[i]-arr[i-2])+minimumEnergyUtill(arr,i-2,dp);
      
      return dp[i]=min(left,right);
  }
  
    int minimumEnergy(vector<int>& arr, int n) {
        // Code here
        vector<int>dp(n,0);
        dp[0]=0;
        dp[1]=abs(arr[1]-arr[0]);
        for(int i=2;i<n;i++){
            
            int left=abs(arr[i]-arr[i-1])+dp[i-1];
            int right=abs(arr[i]-arr[i-2])+dp[i-2];
            
            dp[i]=min(left,right);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends