#include<stdio.h>
int maxContinuous(int a[],int n)
{
	int i,m=0,flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			flag++;
			if(flag>m)
			{
				m=flag;
			}
		}
		else
		{
			flag=0;
		}
	}
	return m;
}

int main()
{
	int a[10]={0,1,1,1,1,1,0,0,0,1};
	int m=maxContinuous(a,10);
	printf("最大连续数字1的个数为：%d",m);
	return 0;
}
 
