//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

bool f(vector<int>&arr,int mid,int cow){
    int x=1,place=arr[0];
    int n=arr.size();
    
    for(int i=1;i<n;i++){
        if(arr[i]-place>=mid){
            x++;
            place=arr[i];
        }
        if(cow==x) return true;
    }
    return false;
}

    int solve(int n, int k, vector<int> &arr) {
    
        // Write your code here
        sort(arr.begin(),arr.end());
        int low=1,high=arr[n-1];
        int res=0,ans=INT_MIN;
        
        while(low<=high){
            int mid=(low+high)/2;
            if(f(arr,mid,k)==true){
                res=mid;
                ans=max(ans,res);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
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

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends