#include<stdio.h>
int enQueue(int a[],int rear,int b) 
{
	a[rear]=b;
	rear++;
	printf("��%d��Ԫ��%d���\n",rear,b);
	return rear;
}
int deQueue(int a[],int front,int rear)
{
	if(front!=rear)
	{	
		printf("��%d��Ԫ��%d����\n",front+1,a[front]);
		front++;
		return front;
	}
}
int main()
{
	int a[10],front,rear;
	front=rear=0;
	rear=enQueue(a,rear,1);
	rear=enQueue(a,rear,2);
	rear=enQueue(a,rear,3);
	rear=enQueue(a,rear,4);
	rear=enQueue(a,rear,5);
	front=deQueue(a,front,rear);
	front=deQueue(a,front,rear);
	front=deQueue(a,front,rear);
	front=deQueue(a,front,rear);
	return 0;
}
