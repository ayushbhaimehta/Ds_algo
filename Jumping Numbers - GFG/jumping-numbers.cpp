//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(long long x, long long num, long long &ans){ 
        
        // Create a queue and enqueue 'num' to it 
        queue<long long> q; 
        q.push(num); 
      
        // Do BFS starting from num 
        while (!q.empty()) { 
            num = q.front(); 
            q.pop(); 
      
            if (num <= x) { 
                // update the answer
                ans = max(ans, num);
                
                int last_dig = num % 10; 
      
                // If last digit is 9, dont append next digit 
                if (last_dig != 9) 
                    q.push((num * 10) + (last_dig + 1)); 
      
                // If last digit is 0, dont append previous digit
                if (last_dig != 0) 
                    q.push((num * 10) + (last_dig - 1)); 
            } 
        } 
    } 

    long long jumpingNums(long long X) {
        
        long long ans=0;
        
        for (long long i = 1; i<=9 && i<=X; i++) 
            bfs(X, i, ans); 
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends