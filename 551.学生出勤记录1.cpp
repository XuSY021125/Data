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
				printf("该学生不能获得出勤奖励");
				return 0; 
			 } 
		}
		if(s[i]=='L')
		{
			late++;
			if(late>=3)
			{
				printf("该学生不能获得出勤奖励");
				return 0;
			}
		}
		else
		{
			late=0;
		}
	}
	printf("该学生可以获得出勤奖励"); 
}
int main()
{
	char *s="PPAPPLL";
	checkRecord(s,7);
	return 0; 
}
