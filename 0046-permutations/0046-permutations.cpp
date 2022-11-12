class Solution {
public:
    
    void f(vector<int>&arr,vector<bool>&freq,vector<int>&temp,vector<vector<int>>&ans){
        
        if(temp.size()==arr.size()) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<arr.size();i++){
            if(freq[i]!=1){
                temp.push_back(arr[i]);
                freq[i]=1;
                f(arr,freq,temp,ans);
                freq[i]=0;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool>freq(n,0);
        vector<vector<int>>ans;
        vector<int>temp;
        f(nums,freq,temp,ans);
        return ans;
    }
};