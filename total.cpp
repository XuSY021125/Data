#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 100     //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10       //���Ա�ռ�ķ�������

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef int Status;
#define OK 1
#define ERROR 0
#define ture 1
#define false 0
#define overflow -1
#define LIST_INIT_SIZE 100
#define LISTINCERMENT 10

typedef struct
{
	ElemType* elem;				//�洢�ռ��ַ
	int length;					//��ǰ����
	int listsize;				//��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
}SqList;

Status InitList_Sq(SqList* L)	//����һ���յ����Ա�L
{
	(*L).elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(*L).elem)
		return overflow;						//�洢�ռ�ʧ��   
	(*L).length = 0;							//�ձ���Ϊ0
	(*L).listsize = LIST_INIT_SIZE;				//��ʼ�洢����
	return OK;
}

Status CreateList_Sq(SqList* L)
{
	int i, n;
	printf("���������Ա���\nn=");
	scanf("%d", &n);
	(*L).length = n;
	(*L).length = n;
	printf("\n�������Ա�L:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &((*L).elem[i]));
	return OK;
}

Status DestroyList_Sq(SqList* L)                     //�������Ա�L
{
	if ((*L).elem)
		free((*L).elem);                     //�ͷ����Ա�ռ�ݵ����д洢�ռ�
	return OK;
}

Status ClearList_Sq(SqList* L)                        //��L����Ϊ�ձ�
{
	(*L).length = 0;                               //�����Ա�ĳ�����Ϊ0
	return OK;
}

Status ListEmpty_Sq(SqList L)                        //���Ա��пա�
{
	if (L.length == 0)
		return TRUE;                         //��LΪ�գ��򷵻�TURE
	else
		return FALSE;                        //��L��Ϊ�գ��򷵻�FALSE
}

Status ListLength_Sq(SqList L)                       //�������Ա�ĳ���
{
	return(L.length);
}

Status GetElem_Sq(SqList L, int i, ElemType* e)       //��e����L�еĵ�i������Ԫ�ص�ֵ
{
	if (i<1 || i>L.length)  return ERROR;            //iֵ���Ϸ�
	*e = L.elem[i - 1];                               //����i������Ԫ�ص�ֵ����e
	return OK;
}

Status LocateElem_Sq(SqList L, int e)
{
	int i;
	for (i = 1; i <= L.length; i++)
	{
		if (L.elem[i - 1] == e)
			return i;
	}
}

Status PriorElem_Sq(SqList L, int i, ElemType cur_e, ElemType* pre_e)
{
	i = LocateElem_Sq(L, cur_e);
	if (i == 1 || i > ListLength_Sq(L)) 
		return 0;
	*pre_e = L.elem[i - 2];                            //��cur_e ��ǰ����ֵ��pre_e
	return OK;
}

Status NextElem_Sq(SqList L, int i, ElemType cur_e, ElemType* next_e)
{
	i = LocateElem_Sq(L, cur_e);
	if (i == ListLength_Sq(L) || i > ListLength_Sq(L)) return 0;
	*next_e = L.elem[i];                            //��cur_e�ĺ�̸�ֵ��next_e
	return OK;
}

Status ListInsert_Sq(SqList* L, int i, ElemType e)     //�����Ա�L�еĵ�i��λ��֮ǰ�����µ�Ԫ��e

{
	ElemType* newbase, * p, * q;
	if (i<1 || i>(*L).length + 1)return ERROR;         //iֵ���Ϸ�
	if ((*L).length >= (*L).listsize)
	{
		newbase = (ElemType*)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);         //�洢����ʧ��
		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;          //�»�ַ
	}
	q = &(*L).elem[i - 1];                             //qΪ����λ��
	for (p = &((*L).elem[(*L).length - 1]); p >= q; --p)
		*(p + 1) = *p;                             //����λ�ü�֮���Ԫ������
	*q = e;                                      //����e
	++(*L).length;                         //����1
	return OK;
}

Status ListDelete_Sq(SqList* L, int i, ElemType* e)      //�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
{
	ElemType* p, * q;
	if (i<1 || i>(*L).length)return ERROR;       //iֵ���Ϸ�
	p = &((*L).elem[i - 1]);                       // pΪ��ɾ��Ԫ�ص�λ��
	*e = *p;                                     //��ɾ��Ԫ�ص�ֵ����e
	q = (*L).elem + (*L).length - 1;                 //��βԪ�ص�λ��
	for (++p; p <= q; ++p)
		*(p - 1) = *p;                         //��ɾ��Ԫ��֮���Ԫ������
	--(*L).length;                             //����1
	return OK;
}

Status ListTraverse_Sq(SqList L, int i)              //���Ա�L�ı���
{
	printf("���Ա�Ϊ: ");
	for (i = 0; i < L.length; i++)
		printf("%4d", (L.elem[i]));
	printf("\n\n");
	return OK;
}

int main()
{
	SqList L;
	ElemType e, cur_e, pre_e, next_e;
	int i, n, select, t;
	InitList_Sq(&L);
	CreateList_Sq(&L);
	printf("\n");
	do {
		printf("**************************************\n");
		printf("1:�ж����Ա��Ƿ�Ϊ��\n");
		printf("2:��ѯ���Ա�ĳ���\n");
		printf("3:�������Ա�ĵ�i��Ԫ��\n");
		printf("4:����ֵΪx��Ԫ�����ڵ�λ��\n");
		printf("5:����Ԫ��x��ǰ��Ϊ\n");
		printf("6:����Ԫ��x�ĺ��Ϊ\n");
		printf("7:�����Ա��i��λ��ǰ������Ԫ��x\n");
		printf("8:ɾ�����Ա��i��Ԫ�أ�������ֵ\n");
		printf("9:�������Ա�\n");
		printf("10:������Ա�\n");
		printf("0:����\n");
		printf("**************************************\n");
		printf("������ѡ��");
		scanf("%d", &select);
		switch (select) {
		case 1: if (ListEmpty_Sq(L))
			printf("���Ա�Ϊ��\n");
			  else
			printf("���Ա�ǿ�\n"); break;

		case 2:ListLength_Sq(L);
			printf("���Ա�ĳ���Ϊ%d\n", (L.length)); break;

		case 3: printf("\ni=");
			scanf("%d", &i);
			if (GetElem_Sq(L, i, &e) == ERROR)
				printf("iֵ���Ϸ�\n");
			else
				printf("��%d��Ԫ�ص�ֵΪ%d\n", i, e); break;

		case 4:printf("\nx=");
			scanf("%d", &e);
			i = LocateElem_Sq(L, e);
			if (i <= L.length)
				printf("��%d��Ԫ�ص�ֵΪ%d\n", i, e);
			else
				printf("���Ա���û��ֵΪ%d��Ԫ��\n", e); break;

		case 5:printf("\nx=");
			scanf("%d", &t);
			if (PriorElem_Sq(L, i, t, &e) == 1)
				printf("Ԫ��%d��ǰ��Ϊ%d\n\n", t, e);
			else
				printf("Ԫ��%d��ǰ��\n", t); break;

		case 6:printf("\nx=");
			scanf("%d", &t);
			if (NextElem_Sq(L, i, t, &e) == 1)
				printf("Ԫ��%d�ĺ��Ϊ%d\n\n", t, e);
			else
				printf("Ԫ��%d�޺��\n", t); break;

		case 7:printf("\ni=");
			scanf("%d", &i, &e);
			printf("\nx=");
			scanf("%d", &e);
			if (ListInsert_Sq(&L, i, e) == ERROR)
				printf("iֵ���Ϸ�\n\n");
			else {
				printf("�µ����Ա�Ϊ: ");
				for (i = 0; i < L.length; i++)
					printf("%4d", (L.elem[i]));
				printf("\n\n");
			}break;

		case 8:printf("\ni=");
			scanf("%d", &i);
			if (ListDelete_Sq(&L, i, &e) == ERROR)
				printf("iֵ���Ϸ�\n\n");
			else {
				printf("��ɾ���ĵ�%d��Ԫ�ص�ֵΪ%d\n", i, e);
				printf("�µ����Ա�Ϊ:");
				for (i = 0; i < L.length; i++)
					printf("%4d", (L.elem[i]));
				printf("\n\n");
			} break;

		case 9:ListTraverse_Sq(L, i); break;

		case 10:ClearList_Sq(&L);
			printf("������Ա�ɹ�,���Ա�����%d \n\n", L.length); break;

		case 0: printf("��������\n"); break;
		default:printf("����ѡ�����! \n");
		}
	} while (select != 0);
	DestroyList_Sq(&L);
}
