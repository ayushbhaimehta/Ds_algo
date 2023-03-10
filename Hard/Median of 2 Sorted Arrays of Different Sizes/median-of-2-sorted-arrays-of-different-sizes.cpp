//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int kElement(vector<int>& arr1, vector<int>& arr2,int k){
        int n=arr1.size(),m=arr2.size();
        if(m > n) {
            return kElement(arr2, arr1, k); 
        }
        int low = max(0,k-m), high = min(k,n);

        while(low<=high){
            int mid=(low+high)/2;
            int cut1=mid;
            int cut2=k-cut1;
            
            int left1=INT_MIN,left2=INT_MIN;
            if(cut1>0){
                left1=arr1[cut1-1];
            }
            if(cut2>0){
                left2=arr2[cut2-1];
            }
            
            int right1=INT_MAX,right2=INT_MAX;
            if(cut1<n){
                right1=arr1[cut1];
            }
            if(cut2<m){
                right2=arr2[cut2];
            }
            
            if(left1<right2 && left2<right1){
                return max(left1,left2);
            }
            else if(left1>right2){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        // Your code goes here
        if(arr1.size()>arr2.size()) return MedianOfArrays(arr2,arr1);
        
        int n=arr1.size(),m=arr2.size();
        int low=0,high=n;
        
        while(high>=low){
            int cut1=(high+low)/2;
            int cut2=((n+m+1)/2)-cut1;
            
            int left1=INT_MIN,left2=INT_MIN;
            if(cut1!=0) left1=arr1[cut1-1];
            if(cut2!=0) left2=arr2[cut2-1];
            
            int right1=INT_MAX,right2=INT_MAX;
            if(cut1!=n) right1=arr1[cut1];
            if(cut2!=m) right2=arr2[cut2];
            
            if(left1<=right2 && left2<=right1){
                if((n+m)%2==0) return ((max(left1,left2)+min(right1,right2))/2.0);
                else return max(left1,left2);
            }
            else if (left1>right2){
                high=cut1-1;
            }
            else{
                low=cut1+1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends