//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    
    struct meet{
        int start;
        int end;
        int pos;
    };
    
    static bool comp(struct meet a, struct meet b){
        if(a.end<b.end) return true;
        else if(a.end>b.end) return false;
        else{
            if(a.pos<b.pos) return true;
            else return false;
        }
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meet meet[n];
        for(int i=0;i<n;i++){
            meet[i].start=start[i];
            meet[i].end=  end[i];
            meet[i].pos=  i+1;
        }
        vector<int>v;
        sort(meet,meet+n,comp);
        int limit=meet[0].end;
        v.push_back(meet[0].pos);
        for(int i=1;i<n;i++){
            if(meet[i].start>limit){
                v.push_back(meet[i].pos);
                limit=meet[i].end;
            }
        }
        int ans=v.size();
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
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends