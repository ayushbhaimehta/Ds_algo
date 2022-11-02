//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    bool flag=0;
    int ans=0,count=k,difference=0;
    for(int i=0;i<n-1;i++)
    {   
        difference=0;
        if ((a[i] + 1) != a[i + 1]) {
            difference += (a[i + 1] - a[i]) - 1;
            if (difference >= count)
            {
                ans=a[i] + count;
                flag=1;
                break;
            }
            else
                count-=difference;
        }
    }
    if(flag)
        return ans;
    return -1;
}