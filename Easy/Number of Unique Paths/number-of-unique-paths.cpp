//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    
    int f(int i,int j,int n,int m,vector<vector<int>>&dp){
        // base condition
        if(i<0 || j<0 || i>n || j>m) return 0;
        if(i==0 && j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left=f(i,j-1,n,m,dp);
        int top=f(i-1,j,n,m,dp);
        
        return dp[i][j]=left+top;
    }
    
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>>dp(a,vector<int>(b,-1));
        return f(a-1,b-1,a,b,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends