#include<stdio.h>

int swap(int *p1,int *p2)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}
int Selectsort(int a[],int i)
{
	int m=i;
	while(i+1<8)
	{
		if(a[m]>a[i+1])
		{
			m=i+1;
		}
		i++;
	}
	return m;
	
 } 
int Sort(int a[])
{
	for(int i=0;i<8;i++)
	{
		int j=Selectsort(a,i);
		if(j!=i)
		{
			swap(&a[j],&a[i]);
		}
	}
}
int main()
{
	int a[8]={6,5,4,9,8,10,11,7};
	Sort(a);
	for(int i=0;i<8;i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
