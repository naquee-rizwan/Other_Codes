#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod=1000000007;
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        string str,boo,expr;
        cin>>str;
        for (ll i=0;i<str.length();i++)
        {
            if (str[i]=='T'||str[i]=='F')
                boo+=str[i];
            else
                expr+=str[i];
        }
        ll dp[boo.length()][boo.length()],dp_[boo.length()][boo.length()];
        for (ll i=0;i<boo.length();i++)
        {
            if (boo[i]=='T')
            {
                dp[i][i]=1;
                dp_[i][i]=0;
            }
            else
            {
                dp[i][i]=0;
                dp_[i][i]=1;
            }
        }
        for (ll i=2;i<=boo.length();i++)
        {
            for (ll j=0;j<=boo.length()-i;j++)
            {
                ll k=j+i-1;
                dp[j][k]=0;
                dp_[j][k]=0;
                for (ll m=j;m<=k-1;m++)
                {
                    if (expr[m]=='&')
                    {
                        dp[j][k]+=(dp[j][m]*dp[m+1][k])%mod;
                        dp[j][k]%=mod;
                        dp_[j][k]+=(dp_[j][m]*dp_[m+1][k])%mod+(dp_[j][m]*dp[m+1][k])%mod+(dp[j][m]*dp_[m+1][k])%mod;
                        dp_[j][k]%=mod;
                    }
                    if (expr[m]=='|')
                    {
                        dp[j][k]+=(dp[j][m]*dp[m+1][k])%mod+(dp_[j][m]*dp[m+1][k])%mod+(dp[j][m]*dp_[m+1][k])%mod;
                        dp[j][k]%=mod;
                        dp_[j][k]+=(dp_[j][m]*dp_[m+1][k])%mod;
                        dp_[j][k]%=mod;
                    }
                    if (expr[m]=='^')
                    {
                        dp[j][k]+=(dp_[j][m]*dp[m+1][k])%mod+(dp[j][m]*dp_[m+1][k])%mod;
                        dp[j][k]%=mod;
                        dp_[j][k]+=(dp_[j][m]*dp_[m+1][k])%mod+(dp[j][m]*dp[m+1][k])%mod;
                        dp_[j][k]%=mod;
                    }
                }
            }
        }
        cout<<dp[0][boo.length()-1]<<endl;
    }
}
