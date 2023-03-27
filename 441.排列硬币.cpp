#include<stdio.h>

int main()
{
	int i,n;
	printf("你拥有的硬币数量为：");
	scanf("%d",&n);
	for(i=1;n>0;i++)
	{
		n=n-i;
	}
	if(n==0)
	{
	 	printf("可形成%d的完整行数",i-1); 
	}
	else
	{
		printf("可形成%d的完整行数",i-2);
	}
	return 0;
}
