#include<stdio.h>

int main()
{
	int target;
	printf("请输入目标值：",target);
	scanf("%d",&target);
	while(target>=1)
	{
		if(target==1)
		{
			return true;
		}
		if(target%2==0)
		{
			target=target/2;
		}
		else
		{
			return false;
		}
	}
	return false;
}
