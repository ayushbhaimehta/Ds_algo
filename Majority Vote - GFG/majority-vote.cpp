//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        vector<int> res;

        unordered_map<int,int> um;
        int target = nums.size()/3;

        for(int i=0;i<nums.size();i++) um[nums[i]]++;
        for(auto& pr : um){
            if(pr.second > target) res.push_back(pr.first);
        }
        
        if(res.empty()) res.push_back(-1);
        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends