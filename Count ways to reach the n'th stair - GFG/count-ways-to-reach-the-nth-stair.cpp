//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int f(int i,vector<int>&dp){
        if(i==0){
            return 1;
        }
        if(i==1) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        int left=f(i-1,dp);
        int right=f(i-2,dp);
        
        return dp[i]=left+right;
    }
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        int dp[n+1];
        int j=1000000007;
        dp[0]=1%j;
        dp[1]=1%j;
        
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%j;            
        }
            
        return dp[n];
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends