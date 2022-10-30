//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int a[], int n) {
        // code here
        vector<int> ans;
        unordered_map<int,vector<pair<int,int>>> mp;
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp.count(a[i]+a[j])){
                    for(auto ele:mp[a[i]+a[j]]){
                        if((ele.first!=i) && (ele.second!=j) && (ele.first!=j) && (ele.second!=i))
                        v.push_back({ele.first,ele.second,i,j});
                    }
                }
                mp[a[i]+a[j]].push_back({i,j});
            }
        }
        if(v.empty()){
            return {-1,-1,-1,-1};
        }
        else{
            return *min_element(v.begin(),v.end());
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends