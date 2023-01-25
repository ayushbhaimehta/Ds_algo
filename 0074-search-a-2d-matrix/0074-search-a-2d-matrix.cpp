class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n=arr.size(),m=arr[0].size();
        int i=n-1,j=0;
        while(i>=0 && j<m){
            if(arr[i][j]>target){
                i--;
            }
            else if(arr[i][j]<target){
                j++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};