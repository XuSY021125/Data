#include<stdio.h> 
int main()
{
	int a[8]={10,22,45,67,1,3,5,7},target;
	printf("ÇëĘäČëtargetľÄÖľŁş");
	scanf("%d",&target);
	int left=0,right=7,mid=(left+right)/2;
	while(left<right)
	{
		mid=(left+right)/2;
		if(a[mid]==target)
		{
			return mid;
		}
		if(a[mid]>=a[left])
		{
			if(a[left]<=target&&a[mid]>=target)
			{
				right=mid;
			}
			else
			{
				left=mid;
			}
		}
		if(a[mid]<=a[right])
		{
			if(a[mid]<=target&&target<a[right])
			{
				left=mid;
			}
			else
			{
				right=mid;
			}
		}
	}
	return -1;
}
