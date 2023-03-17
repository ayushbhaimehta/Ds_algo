//{ Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    
    
    cpp_int solve(int n,vector<cpp_int> & dp)
    {
        if(n<=1)return 1;
        if(dp[n]!=-1) return dp[n];
        cpp_int ans=0;
        for(int i=1;i<=n;i++){
            ans=ans+solve(i-1,dp)*solve(n-i,dp);
        }
        return dp[n]=ans;
    }
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        //code here
        vector<cpp_int> dp(n+1,-1);
        return solve(n,dp);
    }
};

//{ Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends