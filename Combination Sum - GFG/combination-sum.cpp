//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
  vector<vector<int>>ans;
    
    void rec(int i,int sum,vector<int>ds,vector<int> &A, int B){
        if(sum == B){
            ans.push_back(ds);
            return;
        }
        
        if(i >= A.size())
            return;
        
        if(A[i] <= (B-sum)){
            sum += A[i];
            ds.push_back(A[i]);
            rec(i,sum,ds,A,B);
            sum -= A[i];
            ds.pop_back();
        }   
        
        rec(i+1,sum,ds,A,B);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<int>ds;
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        rec(0,0,ds,A,B);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends