#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool is_operator(char op)
{
	if (op=='+'||op=='*')
		return true;
	return false;
}
void Max_Min(string str)
{
	vector <ll> num;
	vector <char> opr;
	string tmp="";
	for (ll i=0;i<str.length();i++)
		if (is_operator(str[i]))
		{
			opr.push_back(str[i]);
			num.push_back(atoi(tmp.c_str()));	// converting the string to integer
			tmp="";
		}
		else
			tmp+=str[i];
	num.push_back(atoi(tmp.c_str()));
	pair <ll,ll> value[num.size()][num.size()];
	for (ll i=0;i<num.size();i++)
		value[i][i].first=value[i][i].second=num[i];
	for (ll len=2;len<=num.size();len++)
		for (ll i=0;i<=num.size()-len;i++)
		{
			ll j=i+len-1;
			value[i][j].first=-1000000000000000000;
			value[i][j].second=1000000000000000000;
			for (ll k=i;k<j;k++)
			{
				ll mini,maxi;
				if (opr[k]=='+')
				{
					maxi=value[i][k].first+value[k+1][j].first;
					mini=value[i][k].second+value[k+1][j].second;
				}
				else if (opr[k]=='*')
				{
					maxi=value[i][k].first*value[k+1][j].first;
					mini=value[i][k].second*value[k+1][j].second;
				}
				value[i][j].first=max(value[i][j].first,maxi);
				value[i][j].second=min(value[i][j].second,mini);
			}
		}
	cout<<"Maximum value:\t"<<value[0][num.size()-1].first<<endl;
	cout<<"Minimum value:\t"<<value[0][num.size()-1].second<<endl;
}
int main()
{
	cout<<"Enter a string:\n";
	string str;
	cin>>str;
	Max_Min(str);
}
