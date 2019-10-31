#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
/* FIRST APPROACH
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,x;
        cin>>n;
        vector <string> str(n);
        string tstr;
        for (ll i=0;i<n;i++)
            cin>>str[i];
        cin>>tstr;
        x=tstr.length();
        ll dp[x];
        for (ll i=0;i<x;i++)
            dp[i]=false;
        for (ll i=0;i<x;i++)
        {
            if (!dp[i])
            {
                string temp=tstr.substr(0,i+1);
                for (ll j=0;j<n;j++)
                    if (temp==str[j])
                    {
                        dp[i]=true;
                        break;
                    }
            }
            if (dp[x-1]==true)
                break;
            if (dp[i])
            {
                for (ll j=i+1;j<x;j++)
                {
                    string temp=tstr.substr(i+1,j-i);
                    for (ll k=0;k<n;k++)
                        if (temp==str[k])
                        {
                            dp[j]=true;
                            break;
                        }
                    if (dp[x-1]==true)
                        break;
                }
            }
        }
        if (dp[x-1])
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
*/
/*SECOND APPROACH
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,x;
        cin>>n;
        vector <string> str(n);
        string tstr;
        for (ll i=0;i<n;i++)
            cin>>str[i];
        cin>>tstr;
        x=tstr.length();
        ll dp[x];
        for (ll i=0;i<x;i++)
            dp[i]=false;
        vector <int> vc;
        vc.push_back(-1);
        for (ll i=0;i<x;i++)
        {
        	ll f=0;
            for (ll j=0;j<vc.size();j++)
            {
            	string temp=tstr.substr(vc[j]+1,i-vc[j]);
            	for (ll k=0;k<n;k++)
            		if (temp==str[k])
            		{
            			f=1;
            			break;
					}
				if (f==1)
				{
					dp[i]=true;
					vc.push_back(i);
					break;
				}
			}
        }
        if (dp[x-1])
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
*/
