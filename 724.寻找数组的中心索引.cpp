#include<stdio.h>

int conter(int *a,int n)
{
	int total,sum1=0,sum2;
	int i;
	for(i=0;i<n;i++)
	{
		total+=a[i];
	}
	sum2=total;
	for(i=0;i<n;i++)
	{
		sum2-=a[i];
		if(sum2==sum1)
		{
			return i;
		}
		sum1+=a[i];
	}
 } 
 
int main()
{
	int a[7]={2,3,1,1,2,6,1};
	return conter(a,7);
}
