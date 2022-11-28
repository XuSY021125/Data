#include<stdio.h>
#include<stdlib.h>
void searchInsert(int* nums, int numsSize, int target)
{
	int flag=0;
	for(int i=0;i<numsSize;i++)
	{
		if(nums[i]==target)
		{
			flag=1;
			printf("目标值的下标为%d\n",i);
			break;
		}
	}
	if(flag==0)
	{
		printf("目标值不存在，按顺序插入目标值，");
		for(int j=numsSize;j>=0;j--)
		{
			if(target>=nums[j-1])
			{
				for(int k=numsSize;k>j;k--)
				{
					nums[k]=nums[k-1];
					nums[k-1]=target;
				}
				printf("插入后目标值的下标为%d。\n",j);	
				break;
			}
		}
	}
}
int main()
{
	int nums[5]={1,3,4,5,7};
	int numsSize=sizeof(nums)/sizeof(nums[0]);
	int target;
	printf("请输入目标值；");
	scanf("%d",&target);
	searchInsert(nums,numsSize,target);
	return 0;
}
