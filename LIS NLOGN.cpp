#include<bits/stdc++.h>
#define inf 10000000
typedef long long ll;
using namespace std;
int main()
{
    ll n;
	cin>>n;
	ll a1[n+1],a2[n+1],lis=0;
	for (ll i=1;i<=n;i++)
		cin>>a1[i];
    a2[0]=-inf;
    for (ll i=1;i<=n;i++)
        a2[i]=inf;
    for (ll i=1;i<=n;i++)
    {
        ll j=lower_bound(a2,a2+1+n,a1[i])-a2;
        lis=max(lis,j);
        a2[j]=a1[i];
    }
    cout<<lis<<endl;
}
