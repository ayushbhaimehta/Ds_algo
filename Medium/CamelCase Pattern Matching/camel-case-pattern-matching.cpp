//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> dict, string pat) {
        // code here
        vector<string>res;
         int m = pat.size();
         if(m <=0) return dict;
         for(int i=0; i<N; i++){
             string temp = dict[i];
             string curr = "";
             int n1 = temp.size();
             for(int i=0; i<n1; i++){
                 if(isupper(temp[i])){
                     curr += temp[i];
                     if(curr == pat) {
                         res.push_back(temp);
                         break;
                     }
                 }
             }
         }
         
         return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends