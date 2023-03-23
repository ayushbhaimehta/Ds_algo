//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        string ans = "";
        stack<char> st;
        for(int i = 0; i < S.length(); i++) {
            if(st.empty() && S[i] == '0') continue;
            else if(st.empty() || st.top() <= S[i]) st.push(S[i]);
            else {
                while(!st.empty() && st.top() > S[i] && K > 0) {
                    st.pop();
                    K--;
                }
                if(S[i] == '0' && st.empty()) continue;
                st.push(S[i]);
            }
        }
        while(K-- && !st.empty()) st.pop(); 
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans == "") ans += '0';
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends