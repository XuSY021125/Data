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
			printf("\n��������������ͬ��0��1����ǰ���أ�");
			return false;
		}
		p=i;
		target=target/2;
	}
	return true;
}
