//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

void f(int i,int sum,vector<int>&arr,vector<int>&ans){
    // base case
    if(i==arr.size()){
        ans.push_back(sum);
        return;
    }
    
    // take
    f(i+1,sum+arr[i],arr,ans);
    // not take
    f(i+1,sum,arr,ans);
}

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        sort(arr.begin(),arr.end());
        vector<int>ans;
        int sum=0;
        f(0,sum,arr,ans);
        sort(ans.begin(),ans.end());
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends