//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
int countRotations(int arr[], int low, int high) {
	    if (high < low) return 0;
	    if (high == low) return low;
	    
	    int mid = (low+high) / 2; 
	    
	    if (mid < high && arr[mid + 1] < arr[mid]) return (mid + 1);
	    else if (mid > low && arr[mid] < arr[mid - 1]) return mid;
	    else if (arr[high] > arr[mid]) return countRotations(arr, low, mid - 1);

	    return countRotations(arr, mid + 1, high);
	}
	int findKRotation(int arr[], int n) {
	    // code here
	    return countRotations(arr, 0, n - 1);
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends