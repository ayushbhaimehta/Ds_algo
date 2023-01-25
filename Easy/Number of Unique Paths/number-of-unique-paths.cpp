//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    
    int f(int i,int j,int n,int m){
        if(i==0&& j==0) return 1;
        if(i<0 || j<0) return 0;
        
        else{
            int left=f(i,j-1,n,m);
            int up  =f(i-1,j,n,m);
            
            return left+up;
        }
    }
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
        //code here
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 // if(dp[i][j]!=-1) return dp[i][j];
                if(i==0 && j==0){
                  dp[i][j]=1;
                      continue;
                }

                int up=0;
                int left = 0;

                if(i>0) 
                    up = dp[i-1][j];
                if(j>0)
                    left = dp[i][j-1];

                dp[i][j] = up+left;
            }
        }
        return dp[m-1][n-1];
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