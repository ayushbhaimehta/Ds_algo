//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        // code here
    	long long int mod = 1e9+7;
    	sort(capacity.begin(), capacity.end());
    	bool flag = false;
    	long long int ans = 1;
    	
    	for(int i = n-1; i>=0; i--){
    		if(capacity[i] < i){
    			flag = true;
    			break;
    		}
    		else ans = (ans % mod * (capacity[i] - i)%mod)%mod;
    	}
    	if(flag) return 0;
    	return int(ans);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends