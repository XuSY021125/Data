#include<stdio.h>

int checkRecord(char *s,int n)
{
	int absent=0,late=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(s[i]=='A')
		{
			absent++;
			if(absent>=2)
			{
				printf("��ѧ�����ܻ�ó��ڽ���");
				return 0; 
			 } 
		}
		if(s[i]=='L')
		{
			late++;
			if(late>=3)
			{
				printf("��ѧ�����ܻ�ó��ڽ���");
				return 0;
			}
		}
		else
		{
			late=0;
		}
	}
	printf("��ѧ�����Ի�ó��ڽ���"); 
}
int main()
{
	char *s="PPAPPLL";
	checkRecord(s,7);
	return 0; 
}
