#include<stdio.h>
int enStack(int a[],int top,int bottom,int b)
{
	top++;
	a[top]=b;
	printf("进栈元素为%d，栈顶为%d\n",b,a[top]);
	return top;
}
int deStack(int a[],int top,int bottom) 
{
	if(top==-1)
	{
		printf("数组为空，没有可出栈的元素\n"); 
	}
	else
	{
		printf("出栈元素为%d，",a[top]); 
		top--;
		printf("栈顶为%d\n",a[top]);	
	}
	return top;
}
int main()
{
	int a[5];
	int top=-1,bottom=0;
	top=enStack(a,top,bottom,1);
	top=enStack(a,top,bottom,3);
	top=enStack(a,top,bottom,5);
	top=deStack(a,top,bottom);
	top=deStack(a,top,bottom);
	top=deStack(a,top,bottom);
	top=deStack(a,top,bottom);
	top=deStack(a,top,bottom);
	top=deStack(a,top,bottom);
	return 0;
}
