#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define ok 1;
#define error 0;
typedef int elemtype;
typedef struct node
{
    elemtype data;	//数据域
    struct node *next;	//指针域,指向下一节点
} node,*linklist;
void createfromhead (linklist L)//利用头插法建立单链表
{
        node *s;
        elemtype c;
        int flag=1;
        while(flag)
        {
                scanf("%d",&c);
                if(c!=0)	//输入0时建表结束 
                {
                        s=(node*)malloc(sizeof(node));	//建立新的结点 
                        s->data=c;	//将c的值赋值给s的数据域 
                        s->next=L->next;	//指针域互换 
                        L->next=s;	//将s的地址赋给上一个结点的地址 
                }
       			 else 
						flag=0;
        } 
} 
void output(linklist L)//遍历输出
{
        node *p;
        for (p=L->next;p!=NULL;p=p->next)
        		printf("%d ",p->data);
}
void createfromtail(linklist L)//尾插法建表 
{
        node *r,*s;		//*r是尾指针
        elemtype c, flag=1;//标志
        r=L;		//动态指向当前表尾
        while(flag)
        {
                scanf("%d",&c);
                if(c!=0)
                {
                        s=(node*)malloc(sizeof(node));
                        s->data=c;
                    	r->next=s;
                    	r=s;
                }        
            else
            {
                    flag=0;
                    r->next=NULL;//最后一结点指针域为空 
            }
        }
} 
int listlength(linklist L)//求单链表的长度
{
        elemtype j;
        node *p;
        p=L->next;
        j=0;//用来存放单链表的长度
        while(p!=NULL)
        {
                p=p->next;
                j++; 
        }
        return j;//单链表的长度 
} 
node* getdata(linklist L,int i)//按序号查找
{
        int j;//j为计数器
        node *p;
        if(i<=0)
	{
        		return NULL;
	}
        p=L;
        j=0;
        while((p->next!=NULL)&&(j<i))
        {
                p=p->next;
                j++;
        }
        if(i==j)
        	return p;//找到第i个节点 
        else 
        	return NULL;
}
node* locate(linklist L,elemtype key)//按内容查找
{
        node *p;
        p=L->next;
        while(p!=NULL)
        if(p->data!=key)
        		p=p->next;
        else
       			break;//退出循环
        return p; 
}
int inslist(linklist L,int i,elemtype e)//单链表的插入
{
        node *pre,*s;
        int k;
        if(i<=0)//插入的位置不合法
        		return error;
        pre=L;
        k=0;
        while(pre!=NULL&&k<i-1)
        //表未查完且未查到第i-1个结点时重复,找到pre指向第i-1个 结点 
        {
                pre=pre->next;
                k=k+1;
        }//查找第i-1个结点
        if(pre==NULL)//插入位置不合法
        		return error;
        s=(node*)malloc(sizeof(node));//申请一个新的结点
        s->data=e;//e放到s的数据域
        s->next=pre->next;//pre next域替换成 s next域
        pre->next=s; 
        return ok;
} 
int dellist(linklist L,int i,elemtype *e)//将删除的元素保存到变量*e 
{
        node *pre,*r;
        int k; 
        pre=L;
        k=0;
        while(pre->next!=NULL&&k<i-1)
        //寻找被删除的结点i的前驱结点i-1,使p指向它
        {
                pre=pre->next;
                k=k+1;
        }
        if(pre->next==NULL)//前驱位置没有找到,删除不合法 
        		return error;
        r=pre->next;//r赋值删除的位置 
        pre->next=r->next;//删除结点
        *e=r->data;
        free(r);//释放
        return ok; 
}
int main()
{
        elemtype a,b,d,e,i,t,y,j=1;
        linklist L;//头指针 
        //单链表的初始化 
    L=(linklist)malloc(sizeof(node));
        L->next=NULL;//null为空指针 
    printf("建立单链表,1代表头插法,0代表尾插法\n");
    printf("请选择: ");
    scanf("%d",&a);
        if(a==1) 
    {
        //接下来利用头插法建表 
            printf("利用头插法建表\n");
        printf("请输入各元素(数字),并使用空格隔开,注意0为结束标志\n");
        createfromhead (L);
        printf("头插法建立成功各元素为:");
    }
    else
    {
            //接下来利用尾插法建表 
            printf("利用尾插法建表\n");
        printf("请输入各元素(数字),并使用空格隔开,注意0为结束标志\n");
        createfromtail(L);
        printf("尾插法建立成功各元素为:");
        }
        output(L);
        printf("\n");
        //接下来是求单链表的长度
        printf("\n单链表的长度为  %d",listlength(L));
        //接下来是按序号查找
        printf("\n开始按序号查找\n");
        printf("请输入需要查找的位置\n");
        printf("请输入:");
        scanf("%d",&b);
        if(getdata(L,b)==NULL)
        printf("查找失败\n");
        else
        printf("查找成功 查找的值为:%d\n",getdata(L,b)->data);
        //接下来是按内容查找
        printf("\n开始按内容查找\n");
        printf("请输入需要查找的内容\n");
        printf("请输入:");
        scanf("%d",&d); 
        //接下来是按内容查找 
        if(locate(L,d)==NULL)
        printf("查找失败\n");
        else
        {
                node *s;
            for (s=L->next;s!=locate(L,d);s=s->next)
                j++;
                printf("查找成功 查找的位置为:%d\n",j);
        }
        //接下来是插入
        printf("开始进行插入\n");
        printf("\n请输入插入的位置:");
        scanf("%d",&i);
        printf("\n请输入插入的元素:");
        scanf("%d",&e);
        if(inslist(L,i,e)==0)
        printf("\n插入失败!\n");
        else
        printf("\n插入成功!\n");
        output(L);
        //接下来是删除
        printf("\n开始进行删除操作\n");
        printf("请输入删除的位置:");
        scanf("%d",&t);
        if(dellist(L,t,&y)==0)
        printf("\n删除失败！\n");
        else
        {
                printf("删除成功,这些元素分别为  "); 
                output(L);
        }
         system("pause"); 
}
