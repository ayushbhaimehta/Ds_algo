//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    vector<int>v(26,0);
		    int n=s.length();
		    int ans=0;
		    int i=0,j=0;
		    while(i<n)
		    {
		        v[s[i]-'A']++;
		        int x=0,s1=0;
		        for(int k=0;k<v.size();k++)
		        {
		            x=max(x,v[k]);
		            s1+=v[k];
		        }
		        x=s1-x;
		        while(x>k and j<n)
		        {
		            v[s[j]-'A']--;
		            int x1=0;
		            s1=0;
		            for(int k=0;k<v.size();k++)
		            {
		                x1=max(x1,v[k]);
		                s1+=v[k];
		            }
		            x=s1-x1;
		            j++;
		        }
		        ans=max(ans,i-j+1);
		        i++;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends