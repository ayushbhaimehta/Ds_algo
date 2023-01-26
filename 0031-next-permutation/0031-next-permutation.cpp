class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        // 1 2 4 5 6
        int n=arr.size();
        int pivot=-1;
        // for keeeping track whether the array is completely reverse sorted
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                pivot=i;
                break;
            }
        }
        // arr is completely reverse sorted in nature
        if(pivot==-1){
            for(int i=0;i<n/2;i++){
                reverse(arr.begin(),arr.end());
                return;
            }
        }
        // something like 1 2 4 5 6
        else{
            for(int i=n-1;i>pivot;i--){
                if(arr[i]>arr[pivot]){
                    swap(arr[pivot],arr[i]);
                    break;
                }
            }
            reverse(arr.begin()+pivot+1,arr.end());
        }
        return;
    }
};