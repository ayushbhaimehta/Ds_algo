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
        int ans=1;
        
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(map.find(arr[i]-1)==map.end()){
                bool flag=true;
                int it=arr[i];
                int currlen=1;
                while(flag){
                    if(map.find(it+1)!=map.end()){
                        it++;
                        currlen++;
                    }
                    else{
                        flag=false;
                    }
                }
                ans=max(ans,currlen);
            }
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