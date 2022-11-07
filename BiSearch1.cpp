#include<stdio.h> 
int locate(int a[],int left,int right)
{

	int mid,target;
	printf("ÇëĘäČëtargetľÄÖľŁş");
	scanf("%d",&target); 
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]==target)
		{
			return mid;
			
		}
		else if(a[mid]<target)
		{
			left=mid+1;
		
		}
		else if(a[mid]>target)
		{
			right=mid-1;
			
		}
	 }
	 if(left==right)
	{
		mid=(a[mid]==target)?mid:-1;
		return mid;
	}
}
int main()
{
	int a[8]={1,4,6,8,10,11,12,16};
	int mid=locate(a,0,7);
	printf("%d",mid);
}
