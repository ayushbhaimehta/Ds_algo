//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int f(int mid,vector<int>& arr,int n){
      int ans=0;
      for(int i=0;i<n;i++){
          ans+=ceil((double)arr[i]/(double)mid);
        //   cout<<ans<<"=ceil vals"<<" ";
      }
    //   cout<<endl;
    //   cout<<ans<<"=ans"<<endl;
      return ans;
  }
  
    int Solve(int n, vector<int>& arr, int h) {
        // Code here
        sort(arr.begin(),arr.end());
        int low=1,high=arr[n-1];
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            int ht=f(mid,arr,n);
            if(ht<=h) ans=min(ans,mid);
            if(ht>h) low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends