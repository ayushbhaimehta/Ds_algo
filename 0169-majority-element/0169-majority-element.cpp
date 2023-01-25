class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n =arr.size();
        int count=1;
        int element=arr[0];
        for(int i=1;i<n;i++){
            if(count==0){
                element=arr[i];
            }
            if(arr[i]==element){
                count++;
            }
            else{
                count--;
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==element){
                count++;
            }   
        }
        
        if(count>n/2){
            return element;
        }
        return -1;
    }
};