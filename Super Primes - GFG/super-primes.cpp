//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	void solve(vector<bool>&vt,int n){
	    vt[0]=false;
	    vt[1]=false;
	    for(int i=2;i<=n;i++){
	        if(vt[i]==false)continue;
	        for(int j=i;j<=n;j+=i){
	            vt[j]=false;
	        }
	        vt[i]=true;
	    }
	}
	int superPrimes(int n)
	{
	    // Your code goes here
	    vector<bool>vt(n+1,true);
	    solve(vt,n);
	    int c=0;
	    for(int i=2;i<=n;i++){
	        if(vt[i] and vt[i-2]){
	           // cout<<i<<" ";
	            c++;
	        }
	    }
	    return c;
	    // 3  11 17 29 37 47
	}
};

//{ Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}

// } Driver Code Ends