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
        printf("请输入学生姓名，年龄：（年龄输入0结束所有输入工作）\n");
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
        printf("无资料。\n");
    else
    {
        c=head;
        while(c->next!=NULL)
        {
            printf("姓名：%s\n年龄：%d\n\n",c->name,c->age);
            c=c->next;
        }
    }
    return 0; 
}
