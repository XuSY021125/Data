#include<stdio.h> 
int move(int a[],int n)
{
	int i,j,k,temp;
	for(i=0;i< n;i++)
	{
		if(a[i]==0)
		{
			for(j=i+1;j<n;j++)
			{
//				a[j-1]=a[j];
				if(a[j]!=0)
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
					break;
				}
			}
		}
	}
	for(k=0;k<n;k++)
	{
		printf("  %d",a[k]);
	}
}
int main()
{
	int a[10]={1,0,2,0,0,3,6,4,0,5};
	int n;
	move(a,10);
	return 0;
}
