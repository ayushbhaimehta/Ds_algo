//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        int sum=0;
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        for(int i=str.length()-1;i>=1;i--){
            if(mp[str[i-1]]<mp[str[i]]){
                sum+=(mp[str[i]]-mp[str[i-1]]);
                i--;
            }else{
                sum+=mp[str[i]];
            }
        }
        if(mp[str[0]]>=mp[str[1]]){
            sum+=mp[str[0]];
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends