//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int>st;
        vector<int>ans,ref;
        int flage=0;
        st.push(asteroids[0]);
        ref.push_back(asteroids[0]);
        for(int i=1;i<N;i++){
            if((st.top()>0 and asteroids[i]>0)  || (st.top()<0 and asteroids[i]<0) || (st.top()<0 and asteroids[i]>0)){
                 st.push(asteroids[i]);
                 ref.push_back(asteroids[i]);
                 flage=0;
            }
            else{
             while(!st.empty() and (st.top()+asteroids[i])<=0){
                 int a = abs(st.top());
                 int b = abs(asteroids[i]);
                 if(st.top()<0 and asteroids[i]<0 || st.top()>0 and asteroids[i]>0 ){
                     st.push(asteroids[i]);
                      ref.push_back(asteroids[i]);
                      flage=0;
                      break;
                 }
                 else if(b>a){
                    st.pop();
                    ref.pop_back();
                    flage =0;
                 }
                 else if (b==a){
                     flage=1;
                    st.pop();
                    ref.pop_back();
                    break;
                 }
                 else{
                    st.push(asteroids[i]);
                    ref.push_back(asteroids[i]);
                    flage=0;
                    break;
             }

             if(st.size()==0 and flage==0){
                 st.push(asteroids[i]);
                 ref.push_back(asteroids[i]);
                 break;
               }

             }
          }
        } 
        return ref;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends