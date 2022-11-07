#include<stdio.h>
int Search(int a[],int i,int target)
{
	while(a[i]!=target)
	{
		i++;
	}
	return i;
 } 
int main()
{
	int a[5]={1,3,4,6,7};
	int i,target;
	printf("ÇëÊäÈëtargetµÄÖµ£º");
	scanf("%d",&target) ;
	int j=Search(a,i,target);
	printf("%d",j);
	return 0;
}
