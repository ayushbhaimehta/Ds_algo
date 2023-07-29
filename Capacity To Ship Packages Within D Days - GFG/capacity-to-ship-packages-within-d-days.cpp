//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  int f(int arr[],int n,int mid){
      int count=1,load=0;
      for(int i=0;i<n;i++){
          if(load+arr[i]>mid){
              load=arr[i];
              count++;
          }
          else{
              load+=arr[i];
          }
      }
      return count;
  }
  
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            sum+=arr[i];
        }
        
        int low=maxi,high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int no=f(arr,n,mid);
            if(no<=d){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends