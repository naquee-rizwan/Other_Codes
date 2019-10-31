#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	string str1,str2;
	cin>>str1>>str2;
	ll len1=str1.length(),len2=str2.length();
	ll mat[len1+1][len2+1];
	for (ll i=0;i<=len2;i++)
		mat[0][i]=0;
	for (ll i=0;i<=len1;i++)
		mat[i][0]=0;
	for (ll i=1;i<=len1;i++)
	{
		for (ll j=1;j<=len2;j++)
		{
			if (str1[i-1]==str2[j-1])
				mat[i][j]=mat[i-1][j-1]+1;
			else
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
		}
	}
	cout<<"The longest common subsequence length:\t"<<mat[len1][len2]<<endl;
	ll i=len1,j=len2;
	cout<<"The longest common subsequence is as follows:\t";
	string str;
	while (i>0&&j>0)
	{
		if (mat[i][j]==mat[i-1][j-1]+1&&str1[i-1]==str2[j-1])
		{
			str+=str1[i-1];
			i--;
			j--;
		}
		else
			if (mat[i][j]==mat[i-1][j])
				i--;
			else
				j--;
	}
	reverse(str.begin(),str.end());
	cout<<str<<endl;
}
