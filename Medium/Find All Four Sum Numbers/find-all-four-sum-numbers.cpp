//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int halfSum = arr[i] + arr[j];
                int low=j+1, high=n-1;
                int sum = k - (halfSum);
                
                while(low<high){
                    if(arr[low] + arr[high] == sum){
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[low]);
                        temp.push_back(arr[high]);
                        ans.push_back(temp);
                        
                        while(low<high && arr[low] == arr[low+1]) low++;
                        while(low<high && arr[high] == arr[high-1]) high--;
                        low++;
                        high--;
                    }
                    
                    else if((arr[low] + arr[high]) < sum) low++;
                    else high--;
                }
                
                while(j+1<n && arr[j+1]==arr[j]) ++j;
                while(i+1<n && arr[i+1]==arr[i]) ++i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends