#include<stdio.h>

int flower(int a[],int len,int n)
{
	int i=0;
	while(n>0&&i<len)
	{
		if(a[i]==1)
		{
			i=i+2;
		} 
		else if(a[i+1]==0||i==len-1)
		{
			n--;
			i=i+2;
		}
		else
		{
			i=i+3;
		}
	}
	return n;
}

int main()
{
	int flowerbed[10]={0,0,1,0,1,0,0,0,0,0};
	int n;	
	printf("��Ҫ�ּ��仨;");
	scanf("%d",&n);
	int b=flower(flowerbed,10,n);
	if(b==0)
	{
		printf("��̳��������%d�仨",n);
	}
	else
	{
		printf("��̳��������%d�仨",n);
	}
	return 0;
 } 
