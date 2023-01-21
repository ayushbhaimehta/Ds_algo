//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         // 1-3 2-4 6-8 9-10
         // 1-4 6-8 9-10
         int n=intervals.size();
         vector<vector<int>>ans;
         sort(intervals.begin(),intervals.end());
         int left=intervals[0][0];
         int right=intervals[0][1];
         for(int i=1;i<n;i++){
             if(intervals[i][0]<=right){
                 right=max(right,intervals[i][1]);
             }
             else{
                 ans.push_back({left,right});
                 left=intervals[i][0];
                 right=intervals[i][1];
             }
         }
         ans.push_back({left,right});
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends