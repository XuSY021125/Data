#include<stdio.h>

void InsertSort(int a[],int n)
{
	int i,j,temp;
	int gap=n;
	do
	{
		gap=gap/3+1;
		for(i=gap;i<n;i++)
		{
			if(a[i]<a[i-gap])
			{
				temp=a[i];
				for(j=i-gap;a[j]>temp&&j>=0;j-=gap)
				{
					a[j+gap]=a[j];	
				}
				a[j+gap]=temp;
			}
		}
	}while(gap>1);
}

int main()
{
	int a[5]={4,1,2,5,3};
	int i;
	InsertSort(a,5);
	printf("排序后的数组为：");
	for(i=0;i<5;i++)
	{
		printf(" %d",a[i]);
	}
	return 0;
}
