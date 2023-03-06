class Solution {
public:
    // better approach using prefix and suffix
    int trap(vector<int>& arr) {
        // so the main idea of this algo is to
        // make 2 arrays called premax and suffmax
        // and then use the formula for that index
        
        int n=arr.size();
        
        // for computing left max
        vector<int>pre(n,-1);
        int preM=0;
        for(int i=0;i<n;i++){
            preM=max(arr[i],preM);
            pre[i]=preM;
        }
        
        // for computing right max
        vector<int>suf(n,-1);
        int suff=arr[n-1];
        for(int i=n-1;i>=0;i--){
            suff=max(arr[i],suff);
            suf[i]=suff;
        }
        
        // actual formula for computing trapped water
        vector<int>stored(n,-1);
        for(int i=0;i<n;i++){
            int ind_water=min(pre[i],suf[i])-arr[i];
            if(ind_water<0) ind_water=0;
            stored[i]=ind_water;
        }
        
        // final iteration for adding stored water of all index
        int tot_water=0;
        for(int i=0;i<n;i++){
            tot_water+=stored[i];
        }
        
        return tot_water;
    }
};