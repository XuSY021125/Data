#include<stdio.h>
int enStack(int a[],int top,int bottom,int b)
{
	top++;
	a[top]=b;
	printf("��ջԪ��Ϊ%d��ջ��Ϊ%d\n",b,a[top]);
	return top;
}
int deStack(int a[],int top,int bottom) 
{
	if(top==-1)
	{
		printf("����Ϊ�գ�û�пɳ�ջ��Ԫ��\n"); 
	}
	else
	{
		printf("��ջԪ��Ϊ%d��",a[top]); 
		top--;
		printf("ջ��Ϊ%d\n",a[top]);	
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
