#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n],lis[n],maxi=1;
    for (ll i=0;i<n;i++)
    {
        cin>>arr[i];
        lis[i]=1;
    }
    for (ll i=1;i<n;i++)
        for (ll j=0;j<i;j++)
            if (arr[i]>arr[j]&&lis[j]+1>lis[i])
                lis[i]=lis[j]+1;
    for (ll i=0;i<n;i++ )
        if (maxi<lis[i])
            maxi=lis[i];
    cout<<maxi;
}
