//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &v,int n){
           //code here
           int ans = 0, prev = 0;
          
           int cnt = 0, first = -1, last;
           for(int j = 0; j < n; j++){
               if(v[j] < 0){
                   cnt++;
                   last = j;
                   if(first == -1) first = j;
               }
               if(v[j] == 0){
                   if(j - prev > 1 || v[prev] > 0){
                       if(cnt % 2)
                           ans = max({ans, j - first - 1, last - prev});
                       else 
                           ans = max(ans, j - prev);
                   }
                   prev = j + 1;
                   cnt = 0, first = -1;
               }
           }
           if(n - prev > 1 || v[prev] > 0){
               if(cnt % 2)
                   ans = max({ans, n - first - 1, last - prev});
               else 
                   ans = max(ans, n - prev);
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends