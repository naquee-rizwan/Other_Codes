#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll binary_search(ll arr[],ll left,ll right,ll find)
{
	if (find<=arr[left])
		return left;
	if (find>arr[right])
		return -1;
	ll mid=left+(right-left)/2;
	if (find==arr[mid])
		return mid;
	else if (arr[mid]<find)
		if (mid+1<=right&&arr[mid+1]>=find)
			return mid+1;
		else
			return binary_search(arr,mid+1,right,find);
	else
		if (mid-1>=left&&arr[mid-1]<find)
			return mid;
		else
			return binary_search(arr,left,mid-1,find);
}
int main()
{
	ll n;
	cin>>n;
	ll arr[n+1];
	for (ll i=1;i<=n;i++)
		cin>>arr[i];
	sort (arr+1,arr+n+1);
	ll find;
	cin>>find;
	ll j=binary_search(arr,1,n,find);
	if (j==-1)
		cout<<"Value not found\n";
	else
	{
		cout<<"value :"<<arr[j]<<endl;	//If you just need the "value" greater than or equal to your finding value, then print out this line.
		//If you need the leftmost "index" whose value is greater than or equal to your finding value, then do this.
		while (j-1>=1 &&arr[j-1]==arr[j])
			j--;
		cout<<"Index :"<<j<<endl;
	}
}
