#include<stdio.h>

int Guess(int g)
{
	int p=12;
	if(p<g)
	{
		return -1;
	}
	if(p==g)
	{
		return 0;
	}
	if(p>g)
	{
		return 1;
	}
}

int main()
{
	int n,guess;
	printf("������²�ķ�Χ��1-");
	scanf("%d",&n);
	printf("��������µ����֣�");
	scanf("%d",&guess);

	int left=1;
	int right=n;
	int mid;
	while(left<right)
	{
		mid=(left+right)/2;
		if(Guess(mid)==0)
		{
			return mid;
		}
		else if(Guess(mid)<0)
		{
			right=mid;
		}
		else if(Guess(mid)>0)
		{
			left=mid+1;
		}
	}
	return left;
}
