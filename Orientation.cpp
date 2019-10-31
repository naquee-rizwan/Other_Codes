#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct point
{
	float x,y;
};
ll orientation(point p1,point p2,point p3)
{
	float k=(p2.y-p1.y)*(p3.x-p2.x)-(p3.y-p2.y)*(p2.x-p1.x);
	if (k==0)
		return 0;	//colinear
	return (k>0)?1:2;	//clockwise or anti-clockwise
}
int main()
{
	point p1,p2,p3;
	cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
	ll op=orientation(p1,p2,p3);
	if (op==0)
		cout<<"Colinear\n";
	else if (op==1)
		cout<<"Clockwise\n";
	else
		cout<<"Counter-Clockwise\n";
}
