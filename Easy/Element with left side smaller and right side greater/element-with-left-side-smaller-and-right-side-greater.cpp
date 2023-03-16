//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    int ans=-1;
    int minn=arr[0];
    for(int i=1;i<n;i++){
        if(minn>arr[i]){
            ans=-1;
        }
        else if(minn<=arr[i]){
            if((ans == -1)&& (i != n-1)){
                ans=arr[i];
            }
            minn=arr[i];
        }
    }
    return ans;
}