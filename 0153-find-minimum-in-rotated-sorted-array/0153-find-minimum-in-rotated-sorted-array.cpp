class Solution {
public:
    int findMin(vector<int>& arr) {
        int low=0,high=arr.size()-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            if(arr[mid]<=arr[ans]){
                ans=mid;
            }
            // 3 4 5 1 2
            // 4 5 1 2 3
        }
        return arr[ans];
    }
};