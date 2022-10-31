#include<stdio.h>
#define long 8
int Qsort(int a[8],int left,int right)
{

	int key=a[left];
	int temp;
	while(1)
	{
		while(a[left]<key&&(left<right))
		{
			left++;
		}
		while(a[right]>key&&(right>left))
		{
			right--;
		}
		if(left>=right)
		{
			break;
		}
		else
		{
			temp = a[left];
   			a[left] = a[right];
    		a[right]=temp;
		}
			if(a[right]==a[left])
		{
			left++;
		}
	}
	return left;
}
int my_qsort(int a[8],int left,int right)
{
	if(left<right)
	{
		int k=Qsort(a,left,right);
		my_qsort(a,left,k-1);
		my_qsort(a,k+1,right);
	}
}
int main()
{
	int a[8]={2,1,5,4,3,6,8,7};
	printf("原数组为：a=");
	for(int i=0;i<long;i++)
	{
		printf("%d",a[i]);
	}
	my_qsort(a,0,long-1);
	printf("\n快速排序后，数组为：a=");
	for(int i=0;i<long;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}

