#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define take ll t;cin>>t;while(t--)
string s;
ll n;
ll Rank[20][100000],arr[100000],lcp[100000],cum[100000];
struct Tuple
{
	int fst,lst,ind;
};
bool cmp(Tuple t1,Tuple t2)
{
	return t1.fst==t2.fst?t1.lst<t2.lst:t1.fst<t2.fst;
}
void suffix_array()
{
	for (ll i=0;i<n;i++)
		Rank[0][i]=s[i]-'a';
	for (ll step=1,cnt=1;(cnt>>1)<n;cnt<<=1,step++)
	{
		Tuple t[n];
		for (ll i=0;i<n;i++)
		{
			t[i].fst=Rank[step-1][i];
			t[i].lst=i+cnt<n?Rank[step-1][i+cnt]:-1;
			t[i].ind=i;
		}
		sort(t,t+n,cmp);
		for (ll i=0;i<n;i++)
			Rank[step][t[i].ind]=i>0&&t[i].fst==t[i-1].fst&&t[i].lst==t[i-1].lst?Rank[step][t[i-1].ind]:i;
	}
	ll cv=log(n)/log(2);
	for (ll i=0;i<n;i++)
		arr[Rank[cv][i]]=i;
}
void lcp__()
{
	ll k=0;
	vector <ll> rank(n);
	for (ll i=0;i<n;i++)
		rank[arr[i]]=i;
	lcp[0]=0;
	for (ll i=0;i<n;i++,k?k--:0)
	{
		if (rank[i]==n-1)
		{
			k=0;
			continue;
		}
		ll j=arr[rank[i]+1];
		while (i+k<n&&j+k<n&&s[i+k]==s[j+k])
			k++;
		lcp[rank[i]+1]=k;
	}
}
int main()
{
	cin>>s;
	n=s.length();
	suffix_array();
	lcp__();
	cum[0]=n-arr[0];
	for (ll i=1;i<n;i++)
		cum[i]=cum[i-1]+(n-arr[i]-lcp[i]);
	take
	{
		ll m;
		cin>>m;
		ll pos=lower_bound(cum,cum+n,m)-cum;
		for (ll i=0,j=arr[pos];i<m-cum[pos-1]+lcp[pos];i++,j++)
			cout<<s[j];
		cout<<endl;
	}
}
