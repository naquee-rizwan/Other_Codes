#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct p
{
	ll start,end;
};
int main()
{
	ll n;
	cin>>n;
	map <ll,ll> m;
	map <ll,ll> :: iterator it;
	p arr[n];
	for (ll i=0;i<n;i++)
	{
		cin>>arr[i].start>>arr[i].end;
		m[arr[i].start]++;
		m[arr[i].end+1]--;
	}
	ll ans=0,cnt=0,maxi=0,sweet=0;
	for (it=m.begin();it!=m.end();it++)
	{
		maxi+=it->second;
		if (maxi>ans)
		{
			ans=maxi;
			sweet=it->first;
		}
	}
	for (ll i=0;i<n;i++)
		if (arr[i].start<=sweet&&arr[i].end>=sweet)
			cnt++;
	cout<<sweet<<" "<<cnt;
}
