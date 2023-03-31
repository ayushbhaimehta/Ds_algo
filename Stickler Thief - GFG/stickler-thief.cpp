//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    
    int f2(int i,int arr[],vector<int>&dp){
        if(i==0){
            return arr[i];
        }
        
        if(dp[i]!=-1) return dp[i];
        int take=arr[i];
        if(i>1) take+=f2(i-2,arr,dp);
        
        int notTake=f2(i-1,arr,dp);
        
        return dp[i]=max(take,notTake);
    }
    
    int f1(int i,int arr[],vector<int>&dp){
        if(i==1){
            return arr[i];
        }
        
        if(dp[i]!=-1) return dp[i];
        int take=arr[i];
        if(i>2) take+=f2(i-2,arr,dp);
        
        int notTake=f2(i-1,arr,dp);
        
        return dp[i]=max(take,notTake);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n,-1);
        int a=f2(n-1,arr,dp);
        return a;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends