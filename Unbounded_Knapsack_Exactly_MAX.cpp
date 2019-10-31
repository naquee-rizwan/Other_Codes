// Author- Naquee Rizwan, College- (IIT (ISM), DHANBAD)
// Admission number- 16JE001866
// Date- 25/02/2018
							// DOCUMENTATION OF PROBLEM
// This is a simple unbounded knapsack problem.
// Unbounded knapsack is when you can choose any item zero or more number of times.
// Here you have to get the maximum total profit by exact (not smaller) knapsack weight 'W' required to be achieved where the values for weight and the corresponding profits are given.
// Note- It is given here that you have to calculate the maximum total profit by using that exact knapsack weight 'W' and not by any weight smaller than 'W'.
#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"Enter the number of the items:\n";
	int n;
	cin>>n;
	pair <int,int> data[n];
	cout<<"Enter the weight and corresponding profit:\n";
	for (int i=0;i<n;i++)
		cin>>data[i].first>>data[i].second;
	cout<<"Enter the knapsack weight:\n";
	int W;
	cin>>W;
	int result[W+1];
	memset(result,0,sizeof(result));
	for (int i=0;i<=W;i++)
		for (int j=0;j<n;j++)
			if ((i-data[j].first)==0||((i-data[j].first)>0&&result[i-data[j].first]!=0))
				result[i]=max(result[i],result[i-data[j].first]+data[j].second);
	cout<<"The maximum profit:\n";
	cout<<result[W]<<endl;
}
