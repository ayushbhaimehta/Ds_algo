class Solution {
public:
    
    void f(int i,vector<int>&arr,vector<int>&temp,vector<vector<int>>&ds){
        if(i>=arr.size()){
            ds.push_back(temp);
            return;
        }
        
        f(i+1,arr,temp,ds);
        temp.push_back(arr[i]);
        f(i+1,arr,temp,ds);
        temp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ds;
        int n=nums.size();
        f(0,nums,temp,ds);
        return ds;
    }
};