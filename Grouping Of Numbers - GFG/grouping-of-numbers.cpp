//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int k) {
        // code here
        vector<int> dp(k);
        for(int i = 0; i < N; i++) {
            dp[arr[i] % k]++;
        }
        int res = dp[0] > 0;
        for (int i = 1; i <= k - i; i++) {
            if (i == k - i) {
                res += dp[k / 2] > 0;
                break;
            }
            res += max(dp[i], dp[k - i]);
        }
        res = max(1, res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends