//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        // code here 
        int zc=0,oc=0,tc=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) zc++;
            else if(arr[i]==1) oc++;
            else tc++;
        }
        // cout<<zc<<"-0s "<<oc<<"-1s "<<tc<<"-2s"<<endl;
        for(int i=0;i<n;i++){
            if(zc>0){
                arr[i]=0;
                zc--;
            }
            else if(oc>0 && zc==0){
                arr[i]=1;
                oc--;
            }
            else if(oc==0 && tc>0){
                arr[i]=2;
                tc--;
            }
        }
        return;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends