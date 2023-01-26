//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      int element=0;
        int ans=1;
        if(n==0){
            return 0;
        }
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
           map[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(map.find(arr[i]-1)!=map.end()){
                continue;
            }
            int count=1;
            element=arr[i];
            while(map.find(element+1)!=map.end()){
               count++;
               element++;
           }
           ans=max(ans,count);
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends