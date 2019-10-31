#include<bits/stdc++.h>
typedef long long ll;
ll mod=1000000007;
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for (ll i=0;i<n;i++)
        cin>>arr[i];
    ll res[m+1];
    memset(res,0,sizeof(res));
    res[0]=1;
    for (ll i=1;i<=m;i++)
        for (ll j=0;j<n;j++)
            if (i>=arr[j])
                res[i]=(res[i]%mod+res[i-arr[j]]%mod)%mod;
    cout<<res[m]%mod<<endl;
}
