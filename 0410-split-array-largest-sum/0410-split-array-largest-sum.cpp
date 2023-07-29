class Solution {
public:
    
    int f(vector<int>&arr,int n,int mid){
        int ans=1,count=0;
        for(int i=0;i<n;i++){
            if(count+arr[i]<=mid){
                count+=arr[i];
            }
            else{
                ans++;
                count=arr[i];
            }
        }
        return ans;
    }
    
    int splitArray(vector<int>& arr, int k) {
        int maxi=INT_MIN,sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        
        int low=maxi,high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int req=f(arr,n,mid);
            if(req<=k) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};