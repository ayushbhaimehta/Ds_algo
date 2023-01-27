class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int left=arr[0][0];
        int right=arr[0][1];
        vector<vector<int>>ans;
        
        for(int i=1;i<n;i++){
            if(arr[i][0]<=right){
                right=max(right,arr[i][1]);
            }
            else{
                vector<int>temp(2);
                temp[0]=left;
                temp[1]=right;
                ans.push_back(temp);
                left=arr[i][0];
                right=arr[i][1];
            }
        }
        vector<int>temp(2);
        temp[0]=left;
        temp[1]=right;
        ans.push_back(temp);
        return ans;
    }
};