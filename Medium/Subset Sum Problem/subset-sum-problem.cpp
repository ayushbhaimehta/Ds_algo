//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

bool isSubsetSumUtill(vector<int>&arr,int i,int target,vector<vector<int>>&dp){
        if(target==0) return true;
        if(i==0) return (arr[0]==target);
        
        if(dp[i][target]!=-1) return dp[i][target];
        
        bool notTake= isSubsetSumUtill(arr,i-1,target,dp);
        
        bool take=false;
        if(target>=arr[i]){
            take=isSubsetSumUtill(arr,i-1,target-arr[i],dp);
        }
        return dp[i][target]=max(take,notTake);
    }



    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        int n= arr.size();
        vector<vector<int>>dp (n+1,vector<int>(sum+1,-1));
        return isSubsetSumUtill(arr,n-1,sum,dp);
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