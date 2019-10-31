#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll fact[5000010],modfact[5000010];
ll powermod(ll x,ll y)
{
	x=x%mod;
	ll res=1;
	while (y)
	{
		if (y&1)
			res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
void factorial()
{
	fact[0]=1;
	modfact[0]=1;
	for(ll i=1;i<=5000000;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		modfact[i]=(modfact[i-1]*powermod(i,mod-2))%mod;
	}
}
int main()
{
    factorial();
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m,x;
        cin>>n>>m>>x;
        if (ceil(n/m)>x)
        {
            cout<<0<<endl;
            continue;
        }
        ll den[n-m+1],pr=m%mod;
        den[0]=1;
        for (ll i=1;i<=n-m;i++)
        {
            den[i]=((pr%mod)*(modfact[i]%mod))%mod;
            pr=((pr%mod)*(m+i)%mod)%mod;
        }
        ll num[n-m+1]={0};
        memset(num,sizeof(num),0);
        num[0]=1;
        for (ll i=1;i*x<=n-m;i++)
            if (i%2==0)
                num[x*i]=(((fact[m]%mod)*(modfact[i]%mod))%mod*(modfact[m-i]%mod))%mod;
            else
                num[x*i]=-(((fact[m]%mod)*(modfact[i]%mod))%mod*(modfact[m-i]%mod))%mod;
        ll sum=0;
        for (ll i=0;i<=n-m;i++)
            sum=((sum%mod)+((num[n-m-i]%mod)*(den[i]%mod))%mod+mod)%mod;
        cout<<sum<<endl;
    }
}
