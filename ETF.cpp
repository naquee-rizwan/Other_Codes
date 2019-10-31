#include<iostream>
using namespace std;
typedef long long ll;
ll arr[1000010];
int main()
{
    for (ll i=1;i<=1000000;i++)
        arr[i]=i;
    for (ll p=2;p<=100;p++)
    {
        if (arr[p]==p)
        {
            arr[p]=p-1;
            for (ll i=2*p;i<=1000000;i+=p)
               arr[i]=(arr[i]/p)*(p-1);
        }
        cout<<p<<" "<<arr[p]<<endl;
    }
    arr[1]++;
    for (ll i=1;i<=1000000;i++)
        arr[i]+=arr[i-1];
    ll t;
    cin>>t;
    while (t--)
    {
        ll k;
        cin>>k;
        cout<<arr[k]<<endl;
    }
}
