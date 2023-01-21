//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        // 1 2 3 6 5 4
        // step 1 find the pivot
        int pivot=-1;        
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]) {
                pivot=i;
                break;
            }
        }
        if(pivot==-1){
            for(int i=0;i<n/2;i++){
                swap(arr[i],arr[n-i-1]);
            }
        }
        else{
            for(int i=n-1;i>pivot;i--){
                if(arr[i]>arr[pivot]){
                    swap(arr[i],arr[pivot]);
                    break;
                }
            }
            reverse(arr.begin()+pivot+1,arr.end());
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends