#include<stdio.h>

int main()
{
	int p=2,i=0;
	int target;
	scanf("%d",&target);
	while(target>0)
	{
		i=target%2;
		printf("%d",i);
		if(p==i)
		{
			printf("\n出现连续两次相同的0或1，提前返回！");
			return false;
		}
		p=i;
		target=target/2;
	}
	return true;
}
