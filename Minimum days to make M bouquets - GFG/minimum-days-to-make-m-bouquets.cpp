//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int f(vector<int>&arr,int k,int m,int n,int mid){
      int count=0;
      for(int i=0;i<n;i++){
          if(arr[i]<=mid) count++;
          else{
             m-=(count/k);
              count=0;
          } 
      }
      m-=(count/k);
      if(m<=0) return true;
      return false;
  }

  
    int solve(int m, int k, vector<int> &arr){
      // Code here
      int n=arr.size();
      long long val = m * 1ll * k * 1ll;
      if(val>n) return -1;
      int low=INT_MAX,high=INT_MIN;
      for(int i=0;i<n;i++){
          low=min(low,arr[i]);
          high=max(high,arr[i]);
      }
      
      while(low<=high){
          int mid=(low+high)/2;
          if(f(arr,k,m,n,mid)==true){
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
      return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends