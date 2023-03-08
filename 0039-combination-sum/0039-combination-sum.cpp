class Solution {
public:
    
    void f(int i,int target,vector<vector<int>>&ans,vector<int>&temp,vector<int>&arr){
        
        int n=arr.size();
    
        // base case
        if(i==n){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
    
        // take case
        if(target>=arr[i]){
            temp.push_back(arr[i]);
            f(i,target-arr[i],ans,temp,arr);
            temp.pop_back();
        }
        
        // not take case
        f(i+1,target,ans,temp,arr);
    
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        int n=candidates.size();
        f(0,target,ans,temp,candidates);
        return ans;
    }
};