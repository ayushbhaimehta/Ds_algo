//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       // Your code here
       stack<int>st;
       vector<int>ans;
       ans.push_back(1);
       st.push(0);
       
       for(int i=1;i<n;i++){
           while(st.empty()==false && arr[st.top()]<=arr[i]){
               st.pop();
           }
           int span;
           if(st.empty()==true){
               span=i+1;
           }
           else{
               span=i-st.top();
           }
           
           st.push(i);
           ans.push_back(span);
       }
       
       return ans;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends