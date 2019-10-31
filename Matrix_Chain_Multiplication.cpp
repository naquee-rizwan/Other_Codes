#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll p[5010];
/*ll function_recursive(ll i,ll j)
{
	if (i==j)
		return 0;
	ll mini=1000000000000000000,cnt;
	for (ll k=i;k<j;k++)
	{
		cnt=function_recursive(i,k)+function_recursive(k+1,j)+p[i-1]*p[k]*p[j];
		mini=min(mini,cnt);
	}
	return mini;
}*/
pair <ll,ll> m[510][510];
void print_parenthesis(ll i,ll j,char &name)
{
	if (i==j)
	{
		cout<<name++;
		return;
	}
	cout<<"(";
	print_parenthesis(i,m[i][j].second,name);
	print_parenthesis(m[i][j].second+1,j,name);
	cout<<")";
}
void function_dp(ll n)
{
	for (ll i=1;i<=n;i++)
		m[i][i].first=0;
	for (ll i=2;i<=n;i++)
		for (ll j=1;j<=n-i+1;j++)
		{
			ll k=j+i-1;
			m[j][k].first=100000000000000;
			for (ll x=j;x<k;x++)
			{
				ll q=m[j][x].first+m[x+1][k].first+p[j-1]*p[x]*p[k];
				if (q<m[j][k].first)
				{
					m[j][k].first=q;
					m[j][k].second=x;
				}
			}
		}
	cout<<"The minimum number of operations required:\t"<<m[1][n].first<<endl;
	char name='A';
	print_parenthesis(1,n,name);
}
int main()
{
	ll n;
	cout<<"Enter the number of matrices:\n";
	cin>>n;
	cout<<"Enter the dimensions:\n";
	for (ll i=0;i<=n;i++)
		cin>>p[i];
	function_dp(n);
}
