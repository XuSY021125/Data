#include<stdio.h>

int detext(char s[],int n)
{
	int i,flag=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			flag++;
		}
	}
	if(s[0]>='A'&&s[0]<='Z'&&flag==1)
	{
		return true;
	}
	if(flag==n-1)
	{
		return true;
	}
	else if(flag==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	char s[4]="USA";
	return detext(s,4);
 } 
