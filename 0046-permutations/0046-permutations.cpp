class Solution {
public:
    
    void f(vector<bool>freq,vector<int>temp,vector<vector<int>>&ans,vector<int>&nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(freq[i]!=1){
                freq[i]=1;
                temp.push_back(nums[i]);
                f(freq,temp,ans,nums);
                temp.pop_back();
                freq[i]=0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>freq(n,0);
        f(freq,temp,ans,nums);
        return ans;
    }
};