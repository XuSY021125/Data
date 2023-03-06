#include<stdio.h>

int main()
{
    int nums[5] = {1,2,0,4,3}, numsSize = 5;
    int a = 1, b=1,i,j,k;
//    printf("请输入给定数组的值;");
//    for (i = 0;i < 5;i++)
//    {
//        scanf("%d", &nums[i]);
//    }
    for (j = 0;j < numsSize;j++)
    { 
    	if(nums[j]<nums[j+1])
    	{
    		b++;
		}
		else
		{
			b=1;
		}
		if(b>a)
		{
			a=b;
		}

	}
	printf("最长为%d",a);
    return 0;
}
