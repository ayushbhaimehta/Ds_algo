//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            vector <int> x,y;
            for(auto j:enemy)
                x.push_back(j[0]);
            for(auto j:enemy)
                y.push_back(j[1]);
            x.push_back(0);
            x.push_back(n+1);
            y.push_back(0);
            y.push_back(m+1);
            sort(x.begin(),x.end());
            sort(y.begin(),y.end());
            int maxx=0,maxy=0;
            for(int i=1;i<x.size();i++)
                maxx=max(maxx,x[i]-x[i-1]-1);
            for(int i=1;i<y.size();i++)
                maxy=max(maxy,y[i]-y[i-1]-1);
            return maxx*maxy;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends