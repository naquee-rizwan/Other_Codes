#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll tree[100001],a[100001];
void build(ll node,ll start,ll end)
{
	if (start==end)
		tree[node]=a[start];
	else
	{
		ll mid=start+(end-start)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
void update(ll node,ll start,ll end,ll idx,ll val)
{
	if (start==end)
	{
		a[idx]=val;
		tree[node]=val;
	}
	else
	{
		ll mid=start+(end-start)/2;
		if (idx>=start&&idx<=mid)
			update(2*node,start,mid,idx,val);
		else
			update(2*node+1,mid+1,end,idx,val);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
ll query(ll node,ll start,ll end,ll l,ll r)
{
	if (l>end||r<start)
		return 0;
	if (l<=start&&end<=r)
		return tree[node];
    ll mid=start+(end-start)/2;
	ll p1=query(2*node,start,mid,l,r);
    ll p2=query(2*node+1,mid+1,end,l,r);
    return p1+p2;
}
int main()
{
	ll n;
	cin>>n;
	for (ll i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	ll q;
	cin>>q;
	while (q--)
	{
		string str;
		cin>>str;
		if (str=="U")
		{
			ll x,y;
			cin>>x>>y;
			update(1,1,n,x,y);
		}
		else
		{
			ll l,r;
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}
	}
}
