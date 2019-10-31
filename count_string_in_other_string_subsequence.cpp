#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	string a,b;			//a is the string in which search has to be done
	cin>>a>>b;
	ll n=a.length(),m=b.length();
	ll arr[n+1][m+1];
	memset(arr,0,sizeof(arr));
	for (ll i=0;i<=m;i++)
		arr[0][i]=0;	//Because no count of strings will be there to be searched in a null string.
	for (ll i=0;i<=n;i++)
		arr[i][0]=1;	//Only because of the null string to be searched in the string.
	for (ll i=1;i<=n;i++)
		for (ll j=1;j<=m;j++)
			if (a[i-1]==b[j-1])
				arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
			else
				arr[i][j]=arr[i-1][j];
	cout<<arr[n][m]<<endl;
}
