//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<int> minPartition(int N)
    {
        // code here
        vector<int>result;
        do{
            if(N>=2000){
                result.push_back(2000);
                N-=2000;
            }
            else if(N>=500){
                result.push_back(500);
                N-=500;
            }
            else if(N>=200){
                result.push_back(200);
                N-=200;
            }
            else if(N>=100){
                result.push_back(100);
                N-=100;
            }
            else if(N>=50){
                result.push_back(50);
                N-=50;
            }
            else if(N>=20){
                result.push_back(20);
                N-=20;
            }
            else if(N>=10){
                result.push_back(10);
                N-=10;
            }
            else if(N>=5){
                result.push_back(5);
                N-=5;
            }
            else if(N>=2){
                result.push_back(2);
                N-=2;
            }
            else {
                result.push_back(1);
                N-=1;
            }
        }while(N>0);
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends