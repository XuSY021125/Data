#include<stdio.h>

int main()
{
	int i,n;
	printf("��ӵ�е�Ӳ������Ϊ��");
	scanf("%d",&n);
	for(i=1;n>0;i++)
	{
		n=n-i;
	}
	if(n==0)
	{
	 	printf("���γ�%d����������",i-1); 
	}
	else
	{
		printf("���γ�%d����������",i-2);
	}
	return 0;
}
