//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   //// Your code goes here
	   k=k%n;
	   reverse(arr,arr+k);
	   reverse(arr+k,arr+n);
	   reverse(arr,arr+n);
	   
	   //sort(arr, arr + k, greater<int>());
	   //sort(arr+k, arr + n, greater<int>());
	   //sort(arr, arr + n, greater<int>());
	   return;
	   
	   
	   //1 2 3 4 5 6 7     ->>>2
	   //2 1 7 6 5 4 3
	   //3 4 5 6 7 2 1
	} 
		 

};

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends