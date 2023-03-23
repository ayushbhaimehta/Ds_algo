//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    #define ll long long int

public:
    ll mod = 1e9 + 7;

    vector<vector<ll>> mulMatrix(vector<vector<ll>> &a, vector<vector<ll>> &b) {
        int n = a.size();
        vector<vector<ll>> ans(n, vector<ll>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    ll temp = (a[i][k] % mod * b[k][j] % mod) % mod;
                    ans[i][j] = (ans[i][j] % mod + temp % mod) % mod;
                }
            }
        }
        return ans;
    }

    vector<vector<ll>> matrixExpo(vector<vector<ll>> &a, ll n) {
        vector<vector<ll>> ans = a;
        n--;
        while(n) {
            if(n&1) {
                ans = mulMatrix(a, ans);
            }
            a = mulMatrix(a, a);
            n >>= 1;
        }
        return ans;
    }


    int FindNthTerm(long long int n) {
        if(n == 0 || n == 1)    return 1;
        
        vector<vector<ll>> coeff = {
            {1, 1},
            {1, 0}
        };
        
        vector<vector<ll>> ans = matrixExpo(coeff, n - 1);
        return (ans[0][0] % mod+ ans[1][0] % mod) % mod;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends