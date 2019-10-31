#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll arr[1000001],tree[2000001],lazy[2000001];
void build(ll node,ll start,ll end)
{
	if (start==end)
		tree[node]=arr[start];
	else
	{
		ll mid=start+(end-start)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
void update(ll node,ll start,ll end,ll l,ll r,ll val)
{
	if (lazy[node]!=0)
	{
		tree[node]+=(end-start+1)*lazy[node];
		if (start!=end)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if (r<start||l>end)
		return;
	if (l<=start&&end<=r)
	{
		tree[node]+=(end-start+1)*val;
		if (start!=end)
		{
			lazy[node*2]+=val;
			lazy[node*2+1]+=val;
		}
		return;
	}
	ll mid=start+(end-start)/2;
	update(2*node,start,mid,l,r,val);
	update(2*node+1,mid+1,end,l,r,val);
	tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(ll node,ll start,ll end,ll l,ll r)
{
	if (l>end||r<start)
		return 0;
	if (lazy[node]!=0)
	{
		tree[node]+=(end-start+1)*lazy[node];
		if (start!=end)
		{
			tree[node*2]+=lazy[node];
			tree[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if (l<=start&&end<=r)
		return tree[node];
	ll mid=start+(end-start)/2;
	return (query(node*2,start,mid,l,r)+query(node*2+1,mid+1,end,l,r));
}
int main()
{
	
}
