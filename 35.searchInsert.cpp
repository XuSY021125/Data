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
			printf("Ŀ��ֵ���±�Ϊ%d\n",i);
			break;
		}
	}
	if(flag==0)
	{
		printf("Ŀ��ֵ�����ڣ���˳�����Ŀ��ֵ��");
		for(int j=numsSize;j>=0;j--)
		{
			if(target>=nums[j-1])
			{
				for(int k=numsSize;k>j;k--)
				{
					nums[k]=nums[k-1];
					nums[k-1]=target;
				}
				printf("�����Ŀ��ֵ���±�Ϊ%d��\n",j);	
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
	printf("������Ŀ��ֵ��");
	scanf("%d",&target);
	searchInsert(nums,numsSize,target);
	return 0;
}
