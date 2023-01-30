//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isSubstr(string A, string B){
        int i=0, j=0;
        int m=A.size(), n=B.size();
        for(i;i<=m-n;i++){
            for(j=0;j<n;j++){
                if(A[i+j]!=B[j]){
                    break;
                }
            }
            if(j==B.size()){
                return 1;
            }
        }
        return 0;
    }
    int minRepeats(string a, string b) {
        // code here
        string temp=a;
        int count=1;
        while(a.size()<b.size()){
            a+=temp;
            count++;
        }
        if(isSubstr(a,b)){
            return count;
        }
        a+=temp;
        count++;
        if(isSubstr(a,b)){
            return count;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends