#include<stdio.h>

int main()
{
	int nums[6] = {}, target, i;
	int left = 0, right = 5, mid = (left + right) / 2;
	printf("请输入给定的目标值;");
	scanf("%d", &target);
	printf("请输入给定的数组;");
	for (i = 0;i < 6;i++)
	{
		scanf("%d", &nums[i]);
	}
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)	//说明target在右区间
		{
			left = mid +1;
		}
		else if (nums[mid] > target)	//说明target在左区间
		{
			right = mid ;
		}
	}
	if (left == right)
	{
		mid = ((nums[mid] == target) ? mid : -1);
		return mid;
	}
}
