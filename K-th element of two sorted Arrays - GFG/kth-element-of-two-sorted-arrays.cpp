//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int l=max(0,k-m),r=min(n,k);
        while(l<=r){
            int x=(l+r)/2;
            int y=k-x;
            int maxlx=(x-1>=0)?arr1[x-1]:INT_MIN;
            int minrx=(x<n)?arr1[x]:INT_MAX;
            int maxly=(y-1>=0)?arr2[y-1]:INT_MIN;
            int minry=(y<m)?arr2[y]:INT_MAX;
            if(maxlx<=minry && maxly<=minrx){
                return max(maxlx,maxly);
            }else if(maxlx>minry){
                r=x-1;
            }else{
                l=x+1;
            }
            
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends