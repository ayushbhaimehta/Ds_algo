//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int arr[], int N, int sum) {

        // code here.
        vector<vector<long long int>>dp(N,vector<long long int>(sum+1,0));
        for(int i=0;i<=sum;i++){
            if(i%arr[0]==0) dp[0][i]=1;
            else dp[0][i]=0;
        }
        
        for(int i=1;i<N;i++){
            for(int T=0;T<=sum;T++){
                long long int notTake=dp[i-1][T];
                long long int take=0;
                if(arr[i]<=T){
                    take= dp[i][T-arr[i]];
              }
              
                dp[i][T]= take+notTake;
            }
        }
        return dp[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends