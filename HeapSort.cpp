#include<stdio.h>
int swap(int a[],int i,int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
int HeapAdjust(int a[],int s,int n)
{
	int i,temp;
	temp=a[s];
	for(i=s*2;i<=n;i*=2)
	{
		if(i<n&&a[i]<a[i+1])
		{
			i++;
		}
		if(temp>=a[i])
		{
			break;
		}
		a[s]=a[i];
		s=i;
	}
	a[s]=temp;
 } 
int HeapSort(int a[],int n)
{
	int i;
	for(i=n/2;i>0;i--)
	{
		HeapAdjust(a,i,n);
	}
	for(i=n;i>1;i--)
	{
		swap(a,1,i);
		HeapAdjust(a,1,i-1);
	}
}
int main()
{
	int a[12]={-1,5,10,11,4,3,8,9,1,7,2,6};
	int i;
	HeapSort(a,11);
	printf("排序后的数组为：");
	for(i=1;i<12;i++)
	{
		printf(" %d",a[i]);
	 }
	 return 0; 
}
