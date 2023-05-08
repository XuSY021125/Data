#include<stdio.h>
#define long 10
int swap(int *a,int low,int high)
{
	int temp;
	temp=a[low];
	a[low]=a[high];
	a[high]=temp;
}
int quick(int *a,int low,int high)
{
	int k=a[low];
	while(1)
	{ 
		while(low<high&&a[low]<k)
		{
			low++;
		}
		while(low<high&&a[high]>k)
		{
			high--;
		}
		if(low>=high)
		{
			break;
		}
		else
		{
			swap(a,low,high);
		}
		if(a[low]==a[high])
		{
			low++;
		}
	}	
	return low;
}

int quicksort(int *a,int low,int high)
{
	int k;
	if(low<high)
	{
		k=quick(a,low,high);
		quicksort(a,low,k-1);
		quicksort(a,k+1,high);
	}
}
int main()
{
	int a[10]={3,1,4,2,5,7,6,1,8,10};
	int s[2];
	quicksort(a,0,long-1);
	for(int i=0;i<long;i++)
	{
		if(a[i]==a[i+1])
		{
			s[0]=i+1;
		}
		if(a[i]!=i+1)
		{
			s[1]=i+1;
		}
	}
	printf(" %d   %d",s[0],s[1]);
	return 0;
}
