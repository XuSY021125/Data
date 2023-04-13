#include<stdio.h>
int find(int a[],int n)
{
	int b[10],c=0;
	int i,k,flag;
	for(i=1;i<=n;i++)
	{
		flag=i;
		for(k=0;k<n;k++)
		{
			if(a[k]==i)
			{
				flag++;
				break;
			}
		} 
		if(flag==i)
		{
			b[c]=i;
			c++;
		}
	}
	for(int j;j<c;j++)
	{
		printf("   %d",b[j]);
	}
}

int main()
{
	int a[9]={1,1,1,4,5,6,8,1,4};
	find(a,9);
	return 0;
 } 
