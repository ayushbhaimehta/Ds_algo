//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        unordered_map<string,pair<int,int> >m;
        for(int i=0;i<n;i++){
            if(m.find(arr[i])!=m.end()){
                m[arr[i]].second++; 
            }
            else{
                m[arr[i]] = {i,1};
            }
        }
        int freq = 0;
        int idx = -1;
        string ans = "";
        for(auto it:m){
        
            if(freq<it.second.second){
                ans = it.first;
                freq = it.second.second;
                idx = it.second.first;
            }
            else if(freq == it.second.second && idx<it.second.first){
                idx = it.second.first;
                ans = it.first;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends