class Solution {
public:
    
//     int f(int i,int j,int n,int m, vector<vector<int>>&dp){
//         if(i==0&& j==0) return 1;
//         if(i<0 || j<0) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int left=f(i,j-1,n,m,dp);
//             int up  =f(i-1,j,n,m,dp);
            
//         return dp[i][j]=left+up;
//     }
    
    int uniquePaths(int m, int n) {
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