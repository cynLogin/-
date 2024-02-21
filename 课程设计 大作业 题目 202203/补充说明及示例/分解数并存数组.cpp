#include<stdio.h>
#include<math.h>
int main()
{
	int m,m1,n,i,t,y=0,a[200]={0};
	printf("m=");
	scanf("%d",&m);
	m1=m;

	n=log10(m1);
	for(i=0;i<=n;i++)
	{	t=m1%10;
		a[i]=t;
		m1=m1/10;
	}

	for(i=n;i>=0;i--)
	{	printf("%d\n",a[i]);
	}
}
