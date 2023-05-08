#include<stdio.h>
#define long 6

double MaxAverage(int *a,int n,int k) 
{
	int i;
	int sum=0,maxSum;
	for(int i=0;i<k;i++)
	{
		sum+=a[i];
	}
	maxSum=sum;
	for(i=k;i<n;i++)
	{
		sum=sum-a[i-k]+a[i];
		maxSum=(maxSum>sum)?maxSum:sum;
	}
	return (double)maxSum/k;
}

int main()
{
	int a[long]={1,12,-5,-6,50,3};
	double maxAverage=MaxAverage(a,long,4);
	printf("���������ƽ����Ϊ%g",maxAverage);
	return 0;
}
