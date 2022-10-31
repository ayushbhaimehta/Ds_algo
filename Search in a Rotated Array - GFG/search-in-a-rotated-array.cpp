//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int nums[], int low, int high, int target){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        while (low <= high) {
        int mid = (low + high) >> 1; 
        if (nums[mid] == target)
          return mid;
    
        if (nums[low] <= nums[mid]) {
            
            if (nums[low] <= target && nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        } 
        else {
            if (nums[mid] <= target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
      }
      return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends