//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& arr, int target) {
        // Code here
        int low=0,high=n-1;  // 1 2 3 4 5 6 7 8    7   6 7 8 1 2 3 4 5
        while (low <= high) {
        int mid = (low + high) /2;
        if (arr[mid] == target)
          return 1;
    
        if (arr[low] <= arr[mid]) {
          if (arr[low] <= target && arr[mid] >= target)
            high = mid - 1;
          else
            low = mid + 1;
        } 
        else {
          if (arr[mid] <= target && target <= arr[high])
            low = mid + 1;
          else
            high = mid - 1;
        }
      }
      return 0; 
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
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends