class Solution {
public:
    
    int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        // base condition
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        // matching conditions
        if(s1[i]==s2[j]){
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
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s1,s2,dp);
    }
};