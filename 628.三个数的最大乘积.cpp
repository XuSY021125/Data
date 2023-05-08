#include<stdio.h>
#define long 8
int swap(int *a,int left,int right)
{
	int temp;
	temp=a[left];
	a[left]=a[right];
	a[right]=temp;
}

int quick(int *a,int left,int right)
{
	int k=a[left];
	while(1)
	{
		while(left<right&&a[left]<k)
		{
			left++;
		}
		while(left<right&&a[right]>k)
		{
			right--;
		}
		if(left>=right)
		{
			break;
		}
		else
		{
			swap(a,left,right);
		}
		if(a[left]==a[right])
		{
			left++;
		}
	}
	return left;
}

int Qsort(int *a,int left,int right)
{
	int k;
	if(left<right)
	{
		k=quick(a,left,right);
		Qsort(a,left,k);
		Qsort(a,k+1,right);
	 } 
}

int main()
{
	int a[long]={-10,-9,4,8,6,7,5,2};
	int max;
	Qsort(a,0,long-1);
	for(int i=0;i<long;i++)
	{
		printf(" %d",a[i]) ;
	}
	max=a[long-1]*a[long-2]*a[long-3];
	if(a[0]<0)
	{
		max=(max>a[0]*a[1]*a[long-1])?max:a[0]*a[1]*a[long-1];
	}
	printf("\nmax=%d",max);
	return 0;
}
