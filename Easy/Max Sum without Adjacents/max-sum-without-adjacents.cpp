//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

int f(int i,int *arr,vector<int>&dp){
    // base codntion
    if(i==0) return arr[i];
    if(i<0) return 0;
    
    if(dp[i]!=-1) return dp[i];
    int take=take=f(i-2,arr,dp)+arr[i];
    // if(i>1){
        
    // }
    int notTake=f(i-1,arr,dp);
    
    return dp[i]=max(take,notTake);
}
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n,-1);
	    return f(n-1,arr,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends