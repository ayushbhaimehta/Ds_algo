//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int i=0;
        int n=s.length();
        int count=0;
        stack<int>index;
        stack<char>stack;
        index.push(-1);
        while(i<n){
            if(s[i]=='('){
                stack.push(s[i]);
                index.push(i);  
            }
            else{
                if(!stack.empty() && stack.top()=='('){
                    stack.pop();
                    index.pop();
                    count=max(count,i-index.top());
                }
                else{
                    index.push(i);   
                }
            }
            i++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends