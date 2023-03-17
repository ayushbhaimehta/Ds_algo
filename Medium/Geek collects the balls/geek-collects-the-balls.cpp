//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxBalls(int N, int M, vector<int> a, vector<int> b) {
        return std::max(
            maxBallsImpl(a, b, a.begin(), b.begin()), 
            maxBallsImpl(b, a, b.begin(), a.begin()));
    }
    
private:

    int maxBallsImpl(vector<int>& first, vector<int>& second, vector<int>::iterator first_it, vector<int>::iterator second_it) {
        if (first_it == first.end())
            return 0;
            
        const auto next_second_it = std::find(second_it, second.end(), *first_it);
        int number = *first_it + maxBallsImpl(first, second, ++first_it, second_it);
        
        if (next_second_it != second.end()) {
            return std::max(
                number,
                maxBallsImpl(second, first, next_second_it, first_it)
            );
        } else {
            return number;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        vector<int> a(N), b(M);
        for(int i = 0;i < N;i++)
            cin>>a[i];
        for(int i = 0;i < M;i++)
            cin>>b[i];
        
        Solution ob;
        cout<<ob.maxBalls(N, M, a, b)<<"\n";
    }
    return 0;
}
// } Driver Code Ends