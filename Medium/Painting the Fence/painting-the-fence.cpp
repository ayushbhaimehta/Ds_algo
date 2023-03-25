//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        if(n==1){return k;}
        if(n==2){int ans=k*k;return ans;}
        if(k==1){return 0;}
        long long pre2=k;
        long long pre1=k*k;
        long long ans;
        for(int i=3;i<=n;i++){
            ans=((k-1)*(pre2+pre1))%1000000007;
            pre2=pre1;
            pre1=ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends