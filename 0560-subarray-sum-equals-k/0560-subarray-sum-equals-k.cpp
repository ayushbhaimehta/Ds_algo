class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int sum=0,ans=0;
        mp[sum]=1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};