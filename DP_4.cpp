#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        ll dp[str1.length()+1][str2.length()+1];
        for (ll i=1;i<=str1.length();i++)
            dp[i][0]=0;
        for (ll i=0;i<=str2.length();i++)
            dp[0][i]=0;
        for (ll i=1;i<=str1.length();i++)
            for (ll j=1;j<=str2.length();j++)
            {
                if (str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        cout<<dp[str1.length()][str2.length()]<<endl;
    }
}
