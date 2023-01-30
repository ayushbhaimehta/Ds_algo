//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        if (n == 1 && m == 1 && (mat[0][0] == 0 || k >= 1))
            return 0;
    
        vector<vector<vector<bool> > > visited(
            n, vector<vector<bool> >(
                   m, vector<bool>(k + 1, false)));
        int steps = 0;
    
        queue<vector<int> > q;
        q.push({ 0, 0, k });
        int ar1[4] = { 1, -1, 0, 0 };
        int ar2[4] = { 0, 0, -1, 1 };
        
        while (!q.empty()) {
            int size = q.size();
    
            steps++;
            while (size--) {
                auto curr = q.front();
                int i = curr[0], j = curr[1], w = curr[2];
                q.pop();
                visited[i][j][w] = true;
                for (int dir = 0; dir < 4; dir++) {
                    int new_x = i + ar1[dir];
                    int new_y = j + ar2[dir];
                    int new_k = w;
                    if (new_x >= 0 && new_x < n && new_y >= 0
                        && new_y < m) {
                        if (mat[new_x][new_y] == 0
                            && !visited[new_x][new_y][new_k]) {
                            if (new_x == n - 1
                                && new_y == m - 1)
                                return steps;
                            q.push({ new_x, new_y, new_k });
                            visited[new_x][new_y][new_k] = true;
                        }
                        else if (mat[new_x][new_y] == 1
                                 && new_k >= 1
                                 && !visited[new_x][new_y]
                                            [new_k - 1]) {
                            if (new_x == n - 1
                                && new_y == m - 1)
                                return steps;
                            q.push({ new_x, new_y, new_k - 1 });
                            visited[new_x][new_y][new_k - 1]
                                = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends