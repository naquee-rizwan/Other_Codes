#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct node
{
	ll val;
	struct node *next;
};
struct node * initialize(ll value)
{
	struct node * head = (struct node *) malloc(sizeof(struct node));
	head->val=value;
	head->next=NULL;
	return head;
}
int main()
{
	struct node * root = NULL;
	cout<<"Enter the number of nodes to enter-\n";
	ll k;
	cin>>k;
	while (k--)
	{
		cout<<"Enter the value to be stored-\n";
		ll tr;
		cin>>tr;
		struct node * temp = initialize(tr);
		if (root==NULL)
			root=temp;
		else
		{
			struct node * temp2, * temp3;
			temp2=root;
			temp3=root->next;
			while (temp3!=NULL)
			{
				temp2=temp3;
				temp3=temp3->next;
			}
			temp2->next=temp;
		}
	}
	cout<<"The output linked list is as follows-\n";
	struct node * temp2=root;
	while (temp2!=NULL)
	{
		cout<<temp2->val<<" ";
		temp2=temp2->next;
	}
}
