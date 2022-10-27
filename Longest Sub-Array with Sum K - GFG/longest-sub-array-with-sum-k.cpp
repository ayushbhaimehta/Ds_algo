//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        // Complete the function
        int res=0;
        int sum=0;
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==k) res=i+1;
            if(map.find(sum)==map.end()){
                map.insert({sum,i});
            }
            if(map.find(sum-k)!=map.end()){
                res=max(res,i-map[sum-k]);
            }
        }
        return res;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends