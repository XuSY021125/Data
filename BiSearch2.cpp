#include<stdio.h>

int main()
{
	int nums[6] = {}, target, i;
	int left = 0, right = 5, mid = (left + right) / 2;
	printf("�����������Ŀ��ֵ;");
	scanf("%d", &target);
	printf("���������������;");
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
		else if (nums[mid] < target)	//˵��target��������
		{
			left = mid +1;
		}
		else if (nums[mid] > target)	//˵��target��������
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
