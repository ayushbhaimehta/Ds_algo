//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		// Your code goes here 
		if (n < 3)
        	return false;
        stack<int> stack;
        int temp[n];
        temp[0] = arr[0];
        for(int i = 1; i <n; i++)
            temp[i] = min(temp[i - 1], arr[i]);
            
        for (int j = n - 1; j >= 0; j--)
		{
            if (arr[j] > temp[j]) 
			{
                while (!stack.empty() && stack.top() <= temp[j])
                    stack.pop();
                if (!stack.empty() && stack.top() < arr[j])
                    return true;
                stack.push(arr[j]);
            }
        }
        return false;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}
// } Driver Code Ends