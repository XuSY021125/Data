#include <stdio.h>
#include <stdlib.h>
//�����нڵ�Ľṹ
typedef struct Link{
    int  elem;
    struct Link *next;
}link;
link * initLink(){
    link * p=NULL;//����ͷָ��
    link * temp = (link*)malloc(sizeof(link));//������Ԫ�ڵ�
    //��Ԫ�ڵ��ȳ�ʼ��
    temp->elem = 1;
    temp->next = NULL;
    p = temp;//ͷָ��ָ����Ԫ�ڵ�
    for (int i=2; i<5; i++) {
        link *a=(link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
}
void display(link *p){
    link* temp=p;//��tempָ������ָ��ͷ���
    //ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
    while (temp) {
        printf("%d ",temp->elem);
        temp=temp->next;
    }
    printf("\n");
}
int main() {
    //��ʼ��������1��2��3��4��
    printf("��ʼ������Ϊ��\n");
    link *p=initLink();
    display(p);
    return 0;
}
