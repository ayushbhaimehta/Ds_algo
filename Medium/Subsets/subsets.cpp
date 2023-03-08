//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void f(int i,vector<int>&arr,vector<int>&temp,vector<vector<int>>&ds){
        if(i>=arr.size()){
            ds.push_back(temp);
            return;
        }
        
        f(i+1,arr,temp,ds);
        temp.push_back(arr[i]);
        f(i+1,arr,temp,ds);
        temp.pop_back();
    }
    
    
    vector<vector<int> > subsets(vector<int>& arr)
    {
        //code here
        // sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int>temp;
        vector<vector<int>>ds;
        f(0,arr,temp,ds);
        sort(ds.begin(),ds.end());
        return ds;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends