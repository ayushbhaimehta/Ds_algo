//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> res;
    int l=0,h=n-1;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(x>arr[m])
            l=m+1;
        else if(x<arr[m])
            h=m-1;
        else
        {
            int q=m;
            while(x==arr[m-1])
                m--;
            res.push_back(m);
            while(x==arr[q+1])
                q++;
            res.push_back(q);
        }
        if(res.size()==2)
            break;
    }
    if(res.size()==0)
    {
        res.push_back(-1);
        res.push_back(-1);
    }
    return res;

}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends