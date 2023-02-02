//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        int n=matrix.size(),m=matrix[0].size();
        int row=0,col=0;
        int ans=0;
        
        int dir=1; //For direction
        int a,b;
        while(row<n && row>=0 && col<m && col>=0){
            a=row,b=col; //Store Last index after which we exit matrix
            if(matrix[row][col]==0){
                if(dir==1)col++;
                if(dir==0)row--;
                if(dir==-1)col--;
                if(dir==2)row++;
            }
            else if(matrix[row][col]==1){
                // Change Direction
                if(dir==1){dir=2;matrix[row][col]=0;row++;}
                else if(dir==0){dir=1;matrix[row][col]=0;col++;}
                else if(dir==-1){dir=0;matrix[row][col]=0;row--;}
                else if(dir==2){dir=-1;matrix[row][col]=0;col--;}
            }
            ans++;
        }
        return {a,b};
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends