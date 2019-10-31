#include<stdio.h>
int main()
{
	double temp,x,sum=0,prod=1;
	scanf("%lf",&x);
	temp=x;
	int i;
	for (i=0;i<10;i++)
	{
		if (i%2)
			sum-=(x/prod);
		else
			sum+=(x/prod);
		x*=(temp*temp);
		prod*=((2*i+2)*(2*i+3));
	}
	printf("%lf\n",sum);
}
