//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        // Code hereint n=intervals.size();
        int n= intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int low=intervals[0][0];
        int high=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=high){
                high=max(high,intervals[i][1]);
            }
            else{
                ans.push_back({low,high});
                low=intervals[i][0];
                high=intervals[i][1];
            }
        }
        ans.push_back({low,high});
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