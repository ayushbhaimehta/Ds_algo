class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n=arr.size();
        int m=arr[0].size();
        int i=n-1,j=0;
	    while(i>=0 && j<m){
	        if(arr[i][j]==target){
	            return 1;
	        }
	        else if(arr[i][j]<target){
	            j++;
	        }
	        else {
	            i--;
	        }
	    }
	    return 0;
    }
};