class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        vector<int>ans;
        stack<int>st;
        int n=arr.size();
        for(int i=n-2;i>=0;i--){
            st.push(arr[i]);
        }
        
        for(int i=n-1;i>=0;i--){
            int temp=-1;
            while(st.empty()==false){
                if(st.top()>arr[i]){
                    temp=st.top();
                    break;
                }
                else{
                    st.pop();
                }
            }
            st.push(arr[i]);
            ans.push_back(temp);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};