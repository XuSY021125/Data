#include<stdio.h>
#define m 8
#define n 3
int merge(int* nums1, int numsSize1, int* nums2, int numsSize2)
{
	int i=0,j,x,a;
	for(j=0;j<n;j++)
	{
		if(nums1[i]<=nums2[j])
		{
			for(x=numsSize1-1;x>i;x--)
			{
				nums1[x+1]=nums1[x];
			}
			nums1[i+1]=nums2[j];
			i=i+2;
		}
		else
		{
			for(x=numsSize1-1;x>=i;x--)
			{
				nums1[x+1]=nums1[x];
			}
			nums1[i]=nums2[j];
			i++;
		}
	}
	for(a=0;a<m;a++)
	{
		printf("%d\n",nums1[a]);
	}

} 
int main()
{
	int nums1[m]={1,3,5,7,9};
	int nums2[n]={2,4,6};
	int numsSize1=sizeof(nums1)/sizeof(nums1[0]);
	int numsSize2=sizeof(nums2)/sizeof(nums2[0]);
	merge(nums1,numsSize1,nums2,numsSize2);
	return 0;
}
