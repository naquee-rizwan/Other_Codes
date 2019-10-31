#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll binary_search(ll arr[],ll left,ll right,ll find)
{
	if (arr[right]<=find)
		return right;
	if (arr[left]>find)
		return -1;
	ll mid=left+(right-left)/2;
	if (arr[mid]==find)
		return mid;
	else if (arr[mid]>find)
		if (mid-1>=left&&arr[mid-1]<=find)
			return mid-1;
		else
			return binary_search(arr,left,mid-1,find);
	else
		if (mid+1<=right&&arr[mid+1]>find)
			return mid;
		else
			return binary_search(arr,mid+1,right,find);
}
int main()
{
	ll n;
	cin>>n;
	ll arr[n+1];
	for (ll i=1;i<=n;i++)
		cin>>arr[i];
	sort (arr+1,arr+n+1);
	ll x;
	cin>>x;
	ll j=binary_search(arr,1,n,x);
	if (j==-1)
		cout<<"No such value exists\n";
	else
	{
		cout<<"Value :"<<arr[j]<<endl;	//If you are trying to search for the "value" just smaller than or equal to the value to be searched.
		//If you are trying to search for the right most "index" to which it is smaller than or equal to, do the folowing.
		while (j+1<=n&&arr[j+1]==arr[j])
			j++;
		cout<<"Index :"<<j<<endl;
	}
}
