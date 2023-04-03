//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

bool f(int i,vector<int>&arr,int k,vector<vector<int>>&dp){
    // base condition
    if(k==0) return 1;
    if(i==0){
        if(arr[i]==k) return true;
        else return false;
    }
    
    if(dp[i][k]!=-1) return dp[i][k];
    
    bool take=0;
    if(arr[i]<=k) take=f(i-1,arr,k-arr[i],dp);
    bool notTake=f(i-1,arr,k,dp);
    
    return dp[i][k]=max(take,notTake);
} 

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,arr,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends