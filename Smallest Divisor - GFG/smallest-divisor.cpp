//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int f(vector<int>&arr,int mid,int k){
      int ans=0,n=arr.size();
      for(int i=0;i<n;i++){
          ans+=ceil((double)arr[i]/(double)mid);
      }
      if(ans<=k) return true;
      return false;
  }
  
    int smallestDivisor(vector<int>& arr, int k) {

        // Write your code here.
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=INT_MAX;
        int low=1,high=arr[n-1];
        while(low<=high){
            int mid=(low+high)/2;
            if(f(arr,mid,k)==true){
                high=mid-1;
                ans=min(ans,mid);
            } 
            else low=mid+1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends