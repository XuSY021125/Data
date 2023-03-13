#include<stdio.h>

int main()
{
	int prices[5]={6,8,2,0,5};
	int profit=0,min=prices[0],i;
	for(i=0;i<5;i++)
	{
		if(min>prices[i])
		{
			min=prices[i];
		}
		else if(prices[i]-min>profit)
		{
			profit=prices[i]-min; 
		}
	}
	return profit;
 } 
