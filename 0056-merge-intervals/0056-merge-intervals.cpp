class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        
        // [1 9] [11 18] [19 20]
        
        int n=arr.size();  // 5
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        // left 1 right 3
        int left=arr[0][0]; // 1
        int right=arr[0][1]; // 2
        
        // trtaver from element i-1
        for(int i=1;i<n;i++){
            if(right>=arr[i][0]){
                right=max(right,arr[i][1]);
            }
            else{
                vector<int>temp;
                temp.push_back(left);
                temp.push_back(right);
                ans.push_back(temp);
                left=arr[i][0];
                right=arr[i][1];
            }
        }
        vector<int>temp;
        temp.push_back(left);
        temp.push_back(right);
        ans.push_back(temp);
        return ans;
    }
};