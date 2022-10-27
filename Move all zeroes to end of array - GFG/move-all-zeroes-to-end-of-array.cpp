//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    bool flag=0;
	    int i=0;
	    for(int it=0;it<n;it++){
	        if(arr[it]==0){
	            flag=1;
	            i=it;
	            break;
	        }
	    }
	    if(flag==0) return;
	    int j=i+1;
	    while(j<n){
	        if(arr[j]!=0){
	            swap(arr[i],arr[j]);
	            i++;
	            j++;
	        }
	        else{
	            j++;
	        }
	    }
	    return;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends