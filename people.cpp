#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct people
{
    char name[10];
    int age;
    struct people * next;
};
int main()
{
    struct people * head=NULL;
    struct people * pre , * c;
    int flag=1;
    while(flag!=0)
    {
        printf("������ѧ�����������䣺����������0�����������빤����\n");
        c=(struct people *)malloc(sizeof(struct people));
        if(head==NULL)
            head=c;
        else
            pre->next=c;
        c->next=NULL;
        scanf("%s",&c->name);
        scanf("%d",&c->age);
        pre=c;
        flag=c->age;
    }
    printf("Output:\n");
    if(head==NULL)
        printf("�����ϡ�\n");
    else
    {
        c=head;
        while(c->next!=NULL)
        {
            printf("������%s\n���䣺%d\n\n",c->name,c->age);
            c=c->next;
        }
    }
    return 0; 
}
