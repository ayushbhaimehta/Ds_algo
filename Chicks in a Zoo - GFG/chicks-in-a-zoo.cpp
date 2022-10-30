//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    if(n<=6){
	        return pow(3,n-1);
	    }
	    long long int dp[n];
	    for(int i=1;i<=6;i++){
	        dp[i]=pow(3,i-1);
	    }
	    dp[7]=726;
	    for(int i=8;i<=n;i++){
	        dp[i] = (dp[i - 1] - (2 * dp[i - 6] / 3)) * 3;
	    }
	    return dp[n];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends