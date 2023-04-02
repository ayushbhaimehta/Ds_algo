//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int f(int i,int j,vector<vector<int>>&arr,vector<vector<int>>&dp){
    int n=arr.size(),m=arr[0].size();
    
    if(i<0 ||j<0 || i>n || j>=m){
        return -1e9;
    }
    if(i==0) return arr[i][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up=arr[i][j]+f(i-1,j,arr,dp);
    int ld=arr[i][j]+f(i-1,j-1,arr,dp);
    int rd=arr[i][j]+f(i-1,j+1,arr,dp);
    
    return dp[i][j]=max(up,max(ld,rd));
}

    int maximumPath(int n, vector<vector<int>> arr)
    {
        // code here
        int sum=0;
        int m=arr[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dp[0][i]=arr[0][i];
            sum=max(sum,dp[0][i]);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                
                int up=-1e9,ld=-1e9,rd=-1e9;
                if(i>0) up=arr[i][j]+dp[i-1][j];
                if(j>0) ld=arr[i][j]+dp[i-1][j-1];
                if(j<n-1) rd=arr[i][j]+dp[i-1][j+1];
    
                dp[i][j]=max(up,max(ld,rd));
                sum=max(sum,dp[i][j]);
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends