#include<stdio.h>
int singleNumber(int a[],int n)
{
	int i,j,flag; 
	for(i=0;i<n;i++)
	{
		flag=1;
		for(j=0;j<n;j++)
		{
			if(j==i)
			{
				continue;
			}
			if(a[i]==a[j])
			{
				flag++;
				break;
			}
		}
		if(flag==1)
		{
			printf("只出现一次的数是：%d",a[i]);
			break;
		}
	}
}
int main()
{
	int a[9]={4,1,1,2,2,3,4,3,9};
	singleNumber(a,9);
	return 0;
} 
