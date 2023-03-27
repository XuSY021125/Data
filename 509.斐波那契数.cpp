#include<stdio.h>
 
int main()
{
	int n,i;
	int a[100]={0,1};
	printf("请输入n的值：");
	scanf("%d",&n);
	for(i=2;i>1;i++)
	{
		a[i]=a[i-1]+a[i-2];
		if(i==n)
		{
			a[n]=a[i];
			printf("值为%d",a[i]);
		}
	}
	return 0;
 } 
