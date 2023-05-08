#include <stdio.h>
int enQueue(int *a,int rear,int data){
    a[rear]=data;
    rear++;
    return rear;
}
int deQueue(int *a,int front,int rear){
    if(front!=rear) 
	{
        printf("出队元素：%d\n",a[front]);
        front++;
    }
    return front;
}
int main() {
    int a[5];
    int front1,rear1;
    front1=rear1=0;
    rear1=enQueue(a, rear1, 1);
    rear1=enQueue(a, rear1, 2);
    rear1=enQueue(a, rear1, 3);
//    rear1=enQueue(a, rear1, 4);
//    rear1=enQueue(a, rear1, 5);

   
    int b[10];
    int front2,rear2;
    front2=rear2=0;
    rear2=enQueue(b, rear2, 1);
    rear2=enQueue(b, rear2, 2);
    rear2=enQueue(b, rear2, 3);
    rear2=enQueue(b, rear2, 4); 
    
    while(rear1<5)
    {
    	a[rear1]=b[rear2-1];
    	if(rear1==4)
    	{
    		printf("区域内已满人！\n");
    		break;
		}
    	rear1++;
    	rear2--;
	}
	for(int i=0;i<=rear1;i++)
	{
		printf(" %d",a[i]);
	}
    return 0;
}
