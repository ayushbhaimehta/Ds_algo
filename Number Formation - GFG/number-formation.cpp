//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++


#define ll long long int

const ll mod = 1000000007;

class Solution {

 

  public:

    

    ll power(ll a ,ll b)

{

    if(b==0)return 1;

    ll temp=power(a,b>>1);

    temp=(temp*temp)%mod;

    if(b&1)temp=(temp*a)%mod;

    return temp;

}

 

ll reverse(ll a)

{

    return power(a,mod-2);

}

 

ll func(ll x,ll y,ll z)

{

    vector<ll> fact(2,1);

    ll temp=x+y+z;

    ll t=2,f=1;

    for(;t<=temp;t++)

    {

        f=(f*t)%mod;

        fact.push_back(f);

    }

 

 

    ll ans=0;

    ll digit=x+y+z;

    ll check=1;

    for(ll i=1;i<=digit;i++)

    {

        temp=0;

        for(ll a=0;a<=x&&a<=i;a++)

        {

            for(ll b=0;b<=i-a&&b<=y;b++)

            {

                ll c=i-a-b;

                if(c>z)continue;

                if(a)

                {

                    ll num=(4*fact[i-1])%mod;

                    ll denom=(fact[a-1]*fact[b])%mod;

                    denom=(denom*fact[c])%mod;

                    denom=reverse(denom);

                    num=(num*denom)%mod;

                    temp=(temp+num)%mod;

                }

                if(b)

                {

                    ll num=(5*fact[i-1])%mod;

                    ll denom=(fact[a]*fact[b-1])%mod;

                    denom=(denom*fact[c])%mod;

                     denom=reverse(denom);

                    num=(num*denom)%mod;

                    temp=(temp+num)%mod;                    

                }

                if(c)

                {

                    ll num=(6*fact[i-1])%mod;

                    ll denom=(fact[a]*fact[b])%mod;

                    denom=(denom*fact[c-1])%mod;

                     denom=reverse(denom);

                    num=(num*denom)%mod;

                    temp=(temp+num)%mod;                    

                }

        

                ll denom=(fact[a-1]*(fact[b]*fact[c])%mod)%mod;

            }

        }

    

        ans=(ans+(temp*check)%mod)%mod;

        check=((check*10)%mod+1)%mod;

    }

    return ans;

}

    int getSum(int X, int Y, int Z) {

        return func(X,Y,Z);

    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        Solution ob;
        cout << ob.getSum(x, y, z) << "\n";
    }
    return 0;
}

// } Driver Code Ends