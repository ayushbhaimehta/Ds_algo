//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution
{
  public:
  long long largestSumCycle(int N, vector<int> e)
  {
    // code here
     ll ans = -1;
    vector<int> vis(N, 0);
    function<ll(int)> dfs = [&](int i){
        vis[i] = 1;
        ll s = 0;
        if(e[i] != -1){
            s = i;
            if(vis[e[i]]) vis[e[i]] = 2;
            else s += dfs(e[i])  ;
        }
        if(vis[i] == 2) ans = max(ans, s), s = 0;
        return s;
    };
    
    for(int i = 0; i < N; i++)
        if(!vis[i]) dfs(i);
    return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends