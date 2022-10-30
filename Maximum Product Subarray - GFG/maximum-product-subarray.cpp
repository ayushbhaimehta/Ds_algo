//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long maxLeft = arr[0];
        long long maxRight = arr[0];
        
        long long prod = 1;
        
        bool zeroPresent =  false;
        
        for(auto i:arr) {
            prod *= i;
            if(i == 0) {
                zeroPresent = true;
                prod = 1;
                continue;
            }
            maxLeft = max(maxLeft,prod);
        }
        
        prod = 1;
        
        for(int j=n-1;j>=0;j--) {
            prod *= arr[j];
            if(arr[j] == 0) {
                zeroPresent = true;
                prod = 1;
                continue;
            }
            maxRight = max(maxRight,prod);
        }
        long long z=0;
        
        if(zeroPresent) return max(max(maxLeft,maxRight),z);
        return max(maxLeft,maxRight);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends