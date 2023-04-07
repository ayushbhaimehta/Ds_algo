class Solution {
public:
    int f(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
    if(i>j) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int maxi=INT_MIN;
    
    for(int k=i;k<=j;k++){
        int coins=arr[i-1]*arr[k]*arr[j+1]+f(i,k-1,arr,dp)+f(k+1,j,arr,dp);
        maxi=max(maxi,coins);
    }
    
    return dp[i][j]=maxi;
}

    int maxCoins(int n, vector<int> &arr) {
        // code here
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,arr,dp);
        
    }
    int maxCoins(vector<int>& arr) {
        int n=arr.size();
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++){
                    int coins=arr[i-1]*arr[k]*arr[j+1]+dp[i][k-1]+dp[k+1][j];
                    maxi=max(maxi,coins);
                }

                dp[i][j]=maxi;                
            }
        }
        return dp[1][n];
    }
};