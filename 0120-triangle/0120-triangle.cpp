class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int> > dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=arr[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<i+1;j++){
                int right=arr[i][j]+dp[i+1][j+1];
                int down =arr[i][j]+dp[i+1][j];
      
                dp[i][j]=min(right,down);
            }
        }
        return dp[0][0];
    }
};