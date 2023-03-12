//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<long long>Pse(vector<long long>ans,long long arr[],int n){
        ans.push_back(0);
        stack<long long>s;
        s.push(0);
        for(int i=1;i<n;i++){
            int temp=0;
            while(s.empty()==false){
                if(arr[s.top()]<arr[i]){
                    temp=s.top();
                    break;
                }
                else{
                    s.pop();
                }
            }
            s.push(i);
            ans.push_back(temp);
        }
        
        return ans;
    }
    
    vector<long long>Nse(vector<long long>ans,long long arr[],int n){
        ans.push_back(n-1);
        stack<int>st;
        st.push(n-1);
        
       for(int i=n-2;i>=0;i--){
            int temp=n-1;
            while(st.empty()==false){
                if(arr[st.top()]<arr[i]){
                    temp=st.top();
                    break;
                }
                else{
                    st.pop();
                }
            }
            st.push(i);
            ans.push_back(temp);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long maxi=0;
        stack<long long>s;
        
        for(int i=0;i<=n;i++){
            while(s.empty() ==false && (i==n || arr[s.top()]>=arr[i])){
                long long height=arr[s.top()];
                s.pop();
                long long width= (s.empty())?i: i-s.top()-1;
                maxi=max(maxi,height*width);
            }
            s.push(i);
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends