//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool ispossible(int x , int d)
  {
      int r = x%10;
      int sum = r;
      if(r==d) return false;
      x = x/10;
      while(x>0)
      {
          r = x%10;
          if(r <= sum || d==r) return false;
          sum +=r;
          x = x/10;
         
      }
      return true;
  }
   void solve(int L , int R, int D, vector<int>& ans)
   {
    //   if(L==R) 
    //   {
    //       if(ispossible(L, D))
    //       {
    //       ans.push_back(L);
    //       }
    //       return;
    //   }
    //   if(ispossible(L, D))
    //   {
    //       ans.push_back(L);
    //   }
    //   solve(L+1, R, D, ans);
      for(int i=L;i<=R;i++)
         {
            // int sum=i%10;

            if(ispossible(i,D))
             ans.push_back(i);

        }
   }
    vector<int> goodNumbers(int L, int R, int D) {
        vector<int> ans;
        solve(L,R, D, ans);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends