//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	bool isValid(int x, int y, int n, int m){
	    if(x >= 0 && y >= 0 && x < n && y < m){
	        return true;
	    }
	    return false;
	}
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        
        int n = grid.size();
        int m = n;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>qu;
        qu.push({grid[0][0], {0,0}});
        dist[0][0] = grid[0][0];
        while(!qu.empty()){
            int cost = qu.top().first;
            int row = qu.top().second.first;
            int col = qu.top().second.second;
            qu.pop();
            if(row == n-1 && col == m-1){
                return dist[n-1][m-1];
            }
            for(int i = 0; i < 4; i++){
                int x = row+dx[i];
                int y = col+dy[i];
                if(isValid(x, y, n, m) && cost+grid[x][y] < dist[x][y]){
                    dist[x][y] = cost+grid[x][y];
                    qu.push({cost+grid[x][y], {x,y}});
                }
            }
        }
        return 0;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends