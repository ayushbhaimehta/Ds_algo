//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        //1201
        //9801 1+10*0+8*100+9*1000;
        int n=str.length();
        int ans=0;
        int counter=1;
        for(int i=n-1;i>=0;i--){
            // cout<<counter<<" counter"<<endl;
            // cout<<str[i]<<" str"<<endl;
            if(i==0){
                if(str[i]=='-' && str[i+1]!='-' && str[i+1]!='+'){
                    return -ans;
                }
                else if(str[i]=='-' && (str[i+1]=='-' || str[i+1]=='+')) return -1;
            }
            if(str[i]-'a'>=0 && str[i]-'a'<=26) return -1;

            int temp=counter*(str[i]-'0');
            // cout<<temp<<" temp"<<endl;
            ans+=temp;
            // cout<<ans<< " ans"<<endl;
            counter=counter*10;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends