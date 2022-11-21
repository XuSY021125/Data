#include<stdio.h>
#define turn 1
#define false -1 
int containsDuplicate(int* nums, int numsSize){
    int i=0; 
    for(i;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]==nums[j])
            {
                return 1;
            }
        }
    }
    return -1;
}
int main()
{
	int nums[5]={1,1,2,3,4};
	int m;
	m=containsDuplicate(nums,sizeof(nums)/sizeof(nums[0]));
	return m;
}
