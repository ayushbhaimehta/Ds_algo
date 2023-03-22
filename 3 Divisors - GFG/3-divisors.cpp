//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> is_prime(1000000+5, true);
        is_prime[0] = is_prime[1] = false;
        int n = 1000000+5;
        for(int x = 2; x*x<=n; x++){
            if(is_prime[x]){
                for(int u = x*x; u<=n; u+=x){
                    is_prime[u] = false;
                }
            }
        }
        for(int x = 2; x<=n; x++){
            is_prime[x]+=is_prime[x-1];
        }
        vector<int> ans;
        for(auto n:query){
            ans.push_back(is_prime[sqrt(n)]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends