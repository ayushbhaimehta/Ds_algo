//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool subset(int arr[],int sum,int n){
       bool t[n+1][sum+1];
       for(int i=0;i<=n;i++){
           for(int j=0;j<=sum;j++){
               if(i==0) t[i][j]=false;
               if(j==0)t[i][j]=true;
           }
       }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=sum;j++){
               if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
               }
               else  t[i][j]=t[i-1][j];        
            }
       }
       return t[n][sum];
   }
   
   int equalPartition(int N, int arr[])
   {   int sum=0;
       for(int i=0;i<N;i++){
       sum+=arr[i];
           
       }
       if(sum%2!=0)return false;
       sum=sum/2;
       // code here
       return subset(arr,sum,N);
   }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends