//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

   vector<vector<int>> lookup ;
    
    public:
    int minDifference(int arr[], int n){
        lookup.clear();
        int sum=0;
        for(int i = 0 ; i < n ; ++i) {
            sum += arr[i];
        }
        lookup.resize(n);
        for(int i=0;i<n;++i){
            lookup[i].assign(sum+1,-1);
        }
        return solve(arr, n - 1, 0, 0);
    }
    int solve(int S[], int n, int S1, int S2)
    {
        // Base case: if the list becomes empty
        if (n < 0) {
            return abs(S1 - S2);
        }
    
        // Construct a unique map key from dynamic elements of the input.
        
        int &ans=lookup[n][S1];
        if(ans != -1)
        return ans;
        int inc = solve(S, n - 1, S1 + S[n], S2);
        int exc = solve(S, n - 1, S1, S2 + S[n]);
        
        ans=min(inc,exc);
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends