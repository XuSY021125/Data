#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define ok 1;
#define error 0;
typedef int elemtype;
typedef struct node
{
    elemtype data;	//������
    struct node *next;	//ָ����,ָ����һ�ڵ�
} node,*linklist;
void createfromhead (linklist L)//����ͷ�巨����������
{
        node *s;
        elemtype c;
        int flag=1;
        while(flag)
        {
                scanf("%d",&c);
                if(c!=0)	//����0ʱ������� 
                {
                        s=(node*)malloc(sizeof(node));	//�����µĽ�� 
                        s->data=c;	//��c��ֵ��ֵ��s�������� 
                        s->next=L->next;	//ָ���򻥻� 
                        L->next=s;	//��s�ĵ�ַ������һ�����ĵ�ַ 
                }
       			 else 
						flag=0;
        } 
} 
void output(linklist L)//�������
{
        node *p;
        for (p=L->next;p!=NULL;p=p->next)
        		printf("%d ",p->data);
}
void createfromtail(linklist L)//β�巨���� 
{
        node *r,*s;		//*r��βָ��
        elemtype c, flag=1;//��־
        r=L;		//��ָ̬��ǰ��β
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
                    r->next=NULL;//���һ���ָ����Ϊ�� 
            }
        }
} 
int listlength(linklist L)//������ĳ���
{
        elemtype j;
        node *p;
        p=L->next;
        j=0;//������ŵ�����ĳ���
        while(p!=NULL)
        {
                p=p->next;
                j++; 
        }
        return j;//������ĳ��� 
} 
node* getdata(linklist L,int i)//����Ų���
{
        int j;//jΪ������
        node *p;
        if(i<=0) 
        		return NULL;
        p=L;
        j=0;
        while((p->next!=NULL)&&(j<i))
        {
                p=p->next;
                j++;
        }
        if(i==j)
        	return p;//�ҵ���i���ڵ� 
        else 
        	return NULL;
}
node* locate(linklist L,elemtype key)//�����ݲ���
{
        node *p;
        p=L->next;
        while(p!=NULL)
        if(p->data!=key)
        		p=p->next;
        else
       			break;//�˳�ѭ��
        return p; 
}
int inslist(linklist L,int i,elemtype e)//������Ĳ���
{
        node *pre,*s;
        int k;
        if(i<=0)//�����λ�ò��Ϸ�
        		return error;
        pre=L;
        k=0;
        while(pre!=NULL&&k<i-1)
        //��δ������δ�鵽��i-1�����ʱ�ظ�,�ҵ�preָ���i-1�� ��� 
        {
                pre=pre->next;
                k=k+1;
        }//���ҵ�i-1�����
        if(pre==NULL)//����λ�ò��Ϸ�
        		return error;
        s=(node*)malloc(sizeof(node));//����һ���µĽ��
        s->data=e;//e�ŵ�s��������
        s->next=pre->next;//pre next���滻�� s next��
        pre->next=s; 
        return ok;
} 
int dellist(linklist L,int i,elemtype *e)//��ɾ����Ԫ�ر��浽����*e 
{
        node *pre,*r;
        int k; 
        pre=L;
        k=0;
        while(pre->next!=NULL&&k<i-1)
        //Ѱ�ұ�ɾ���Ľ��i��ǰ�����i-1,ʹpָ����
        {
                pre=pre->next;
                k=k+1;
        }
        if(pre->next==NULL)//ǰ��λ��û���ҵ�,ɾ�����Ϸ� 
        		return error;
        r=pre->next;//r��ֵɾ����λ�� 
        pre->next=r->next;//ɾ�����
        *e=r->data;
        free(r);//�ͷ�
        return ok; 
}
int main()
{
        elemtype a,b,d,e,i,t,y,j=1;
        linklist L;//ͷָ�� 
        //������ĳ�ʼ�� 
    L=(linklist)malloc(sizeof(node));
        L->next=NULL;//nullΪ��ָ�� 
    printf("����������,1����ͷ�巨,0����β�巨\n");
    printf("��ѡ��: ");
    scanf("%d",&a);
        if(a==1) 
    {
        //����������ͷ�巨���� 
            printf("����ͷ�巨����\n");
        printf("�������Ԫ��(����),��ʹ�ÿո����,ע��0Ϊ������־\n");
        createfromhead (L);
        printf("ͷ�巨�����ɹ���Ԫ��Ϊ:");
    }
    else
    {
            //����������β�巨���� 
            printf("����β�巨����\n");
        printf("�������Ԫ��(����),��ʹ�ÿո����,ע��0Ϊ������־\n");
        createfromtail(L);
        printf("β�巨�����ɹ���Ԫ��Ϊ:");
        }
        output(L);
        printf("\n");
        //��������������ĳ���
        printf("\n������ĳ���Ϊ  %d",listlength(L));
        //�������ǰ���Ų���
        printf("\n��ʼ����Ų���\n");
        printf("��������Ҫ���ҵ�λ��\n");
        printf("������:");
        scanf("%d",&b);
        if(getdata(L,b)==NULL)
        printf("����ʧ��\n");
        else
        printf("���ҳɹ� ���ҵ�ֵΪ:%d\n",getdata(L,b)->data);
        //�������ǰ����ݲ���
        printf("\n��ʼ�����ݲ���\n");
        printf("��������Ҫ���ҵ�����\n");
        printf("������:");
        scanf("%d",&d); 
        //�������ǰ����ݲ��� 
        if(locate(L,d)==NULL)
        printf("����ʧ��\n");
        else
        {
                node *s;
            for (s=L->next;s!=locate(L,d);s=s->next)
                j++;
                printf("���ҳɹ� ���ҵ�λ��Ϊ:%d\n",j);
        }
        //�������ǲ���
        printf("��ʼ���в���\n");
        printf("\n����������λ��:");
        scanf("%d",&i);
        printf("\n����������Ԫ��:");
        scanf("%d",&e);
        if(inslist(L,i,e)==0)
        printf("\n����ʧ��!\n");
        else
        printf("\n����ɹ�!\n");
        output(L);
        //��������ɾ��
        printf("\n��ʼ����ɾ������\n");
        printf("������ɾ����λ��:");
        scanf("%d",&t);
        if(dellist(L,t,&y)==0)
        printf("\nɾ��ʧ�ܣ�\n");
        else
        {
                printf("ɾ���ɹ�,��ЩԪ�طֱ�Ϊ  "); 
                output(L);
        }
         system("pause"); 
}
