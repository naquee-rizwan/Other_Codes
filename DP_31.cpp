#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[101][101];
ll dp_(ll arr[],ll str,ll ed)
{
    if (str==ed)
        return arr[str];
    if (str+1==ed)
        return max(arr[str],arr[ed]);
    if (dp[str][ed]!=-1)
        return dp[str][ed];
    dp[str][ed]=max(arr[str]+min(dp_(arr,str+2,ed),dp_(arr,str+1,ed-1)),
	arr[ed]+min(dp_(arr,str+1,ed-1),dp_(arr,str,ed-2)));
    return dp[str][ed];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for (ll i=0;i<n;i++)
            cin>>arr[i];
        for (ll i=0;i<=100;i++)
            for (ll j=0;j<=100;j++)
                dp[i][j]=-1;
        cout<<dp_(arr,0,n-1)<<endl;
    }
}
