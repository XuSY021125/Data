#include <stdio.h>
#include <stdlib.h>
typedef struct QNode{
    int data;
    struct QNode * next;
}QNode;
QNode * initQueue(){
    QNode * queue=(QNode*)malloc(sizeof(QNode));
    queue->next=NULL;
    return queue;
}
QNode* enQueue(QNode * rear,int data){
    QNode * enElem=(QNode*)malloc(sizeof(QNode));
    enElem->data=data;
    enElem->next=NULL;
    //ʹ��β�巨������������������Ԫ��
    rear->next=enElem;
    rear=enElem;
    return rear;
}
QNode* DeQueue(QNode * top,QNode * rear){
    if (top->next==NULL) {
        printf("\n����Ϊ��");
        return rear;
    }
    QNode * p=top->next;
    printf("%d ",p->data);
    top->next=p->next;
    if (rear==p) {
        rear=top;
    }
    free(p);
    return rear;
}
int main() {
    QNode * queue,*top,*rear;
    queue=top=rear=initQueue();//����ͷ���
    //�������������ӽ�㣬ʹ��β�巨���ӵ�ͬʱ����βָ����Ҫָ�����������һ��Ԫ��
    rear=enQueue(rear, 1);
    rear=enQueue(rear, 2);
    rear=enQueue(rear, 3);
    rear=enQueue(rear, 4);
    //�����ɣ���������Ԫ�ؿ�ʼ������
    rear=DeQueue(top, rear);
    rear=DeQueue(top, rear);
    rear=DeQueue(top, rear);
    rear=DeQueue(top, rear);
    rear=DeQueue(top, rear);
    return 0;
}