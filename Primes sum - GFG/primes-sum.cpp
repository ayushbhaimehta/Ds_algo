//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string isSumOfTwo(int N){
        // code here
        set<int> s;
        s.insert(2);
        if(N==4) return "Yes";
        for(int i=3;i<=N;i++){
               int flag = 1;
           for(int j=2;j<=sqrt(i);j++){
               if(i%j==0){
                   flag = 0;
                   break;
               }
           }
           if(flag){
               if(s.find(N-i)!=s.end())
               return "Yes";
               s.insert(i);
           }
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends