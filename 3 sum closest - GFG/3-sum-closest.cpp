//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int arr[], int n, int t)
    {
        // code here
        sort(arr, arr+n);
        int ans = INT_MIN;
        for(int first = 0;first<=n-3;first++){
            int sec = first+1, third = n-1;
            while(sec < third){
                int sumtemp = arr[first] + arr[sec] + arr[third];
                if(sumtemp == t){
                    return sumtemp;
                }
                if(sumtemp < t ){
                    if(ans == INT_MIN) ans = sumtemp;
                    else{
                        if(abs(ans-t) > abs(sumtemp-t)) ans = sumtemp;
                    }
                    sec++;
                }
                else{
                    third--;
                    if(ans == INT_MIN) ans = sumtemp;
                    else{
                        if(abs(ans-t) > abs(sumtemp-t)) ans = sumtemp;
                    }
                }
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends