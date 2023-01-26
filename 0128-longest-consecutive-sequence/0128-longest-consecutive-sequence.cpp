class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        int element=0;
        int ans=1;
        if(n==0){
            return 0;
        }
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
           map[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(map.find(arr[i]-1)!=map.end()){
                continue;
            }
            int count=1;
            element=arr[i];
            while(map.find(element+1)!=map.end()){
               count++;
               element++;
           }
           ans=max(ans,count);
        }
        return ans;
    }
};