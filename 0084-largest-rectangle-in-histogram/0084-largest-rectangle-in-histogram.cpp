class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>s;
        int maxi=0;
        int n=arr.size();
        
        for(int i=0;i<=n;i++){
            while(s.empty()==false && (i==n || arr[s.top()]>=arr[i])){
                int height=arr[s.top()];
                s.pop();
                int width;
                if(s.empty()==true){
                    width=i;
                }
                else{
                    width=i-s.top()-1;
                }
                maxi=max(maxi,width*height);
            }
            s.push(i);
        }
        
        return maxi;
    }
};