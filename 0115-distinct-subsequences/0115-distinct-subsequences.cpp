class Solution {
public:
    int prime=1e9+7;
    
    int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        // base condition
        if(j==0) return 1;
        if(i==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        // matching conditions
        if(s1[i-1]==s2[j-1]){
            // take
            int take=f(i-1,j-1,s1,s2,dp);
            //not take
            int notTake=f(i-1,j,s1,s2,dp);
            
            return dp[i][j]=take+notTake;
        }
        else{
            // not matching
            return dp[i][j]=f(i-1,j,s1,s2,dp);
        }
    }
    
    int numDistinct(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                // not matching
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return (int)dp[n][m];
    }
};