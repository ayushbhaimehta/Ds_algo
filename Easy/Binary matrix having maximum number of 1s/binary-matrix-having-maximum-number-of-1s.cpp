//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> arr, int n) {
        //code here
        int j=n-1,count=0,row=0;
        for(int i=0;i<n;i++){
            bool flag=0;
            while(j>=0 && arr[i][j]==1){
                count=max(n-j,count);
                j--;
                flag=true;
            }
            if(flag==true) row=i;
        }
        
        vector<int>ans;
        ans.push_back(row);
        ans.push_back(count);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends