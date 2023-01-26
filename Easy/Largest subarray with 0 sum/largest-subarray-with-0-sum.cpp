//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        unordered_map<int,int>um;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int currlen=0;
            sum+=arr[i];
            if(sum==0){
                currlen=i+1;
                ans=max(currlen,ans);
                currlen=0;
            }
            if(um.find(sum)!=um.end()){
                currlen=i-um[sum];
                ans=max(ans,currlen);
            }
            else{
                um[sum]=i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends