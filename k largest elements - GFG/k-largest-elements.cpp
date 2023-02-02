//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int a[], int n, int k) {
	    // code here
	    vector<int>v; 
	    int c=k;
	    sort(a,a+n);
	    for(int i=n-1;i>=0;i--)
	    {   
	        
	        if(c!=0)
	        v.push_back(a[i]);
	        else
	        break; 
	        c--;
	    } 
	    return v;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends