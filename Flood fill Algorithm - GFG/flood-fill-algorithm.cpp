//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int n) {
        // Code here 
        int c=image[sr][sc];
        if(c==n){
            return image;
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        while(!q.empty()){
            int p=q.front().first;
            int r=q.front().second;
            image[p][r]=n;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0||j==0){
                        if(p+i>=0&&p+i<image.size()&&
                            r+j>=0&&r+j<image[0].size()&&
                            image[p+i][r+j]==c&&
                            !vis[p+i][r+j])
                        {
                            q.push({p+i,r+j});
                            vis[p+i][r+j]=1;
                        }
                    }
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends