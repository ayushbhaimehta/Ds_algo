//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        // code here 
        vector<bool>flag(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){
                    flag[i]=0;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(flag[i]==1){
                bool check=true;
                for(int j=0;j<n;j++){
                    if(j==i) continue;
                    if(arr[j][i]!=1){
                        check=false;
                    }
                }
                
                if(check==true) return i;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends