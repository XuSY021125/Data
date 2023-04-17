#include<stdio.h>

int duration(int a[],int n)
{
	int i,time=0;
	if(a[0]>=0)
	{
		time=2;
	}
	for(i=1;i<n;i++)
	{
		if(a[i]-a[i-1]>=2)
		{
			time=time+2;
		}
		else if(a[i]-a[i-1]==1)
		{
			time++;
		}
	}
	return time;
}

int main()
{
	int a[5]={1,3,4,6,7};
	int t=duration(a,5);
	printf("中毒持续时间为%d",t);
	return 0;
}
