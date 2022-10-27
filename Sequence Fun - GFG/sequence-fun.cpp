//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    long long int mod=1e9+7;
    
	public:
		int NthTerm(int n){
		    // Code  here
		    if(n==1) return 2;
		    long long int prev=NthTerm(n-1)%mod;
		    prev=(prev*n)%mod;
		    long long int ans=(prev+1)%mod;
		    return (int)ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends