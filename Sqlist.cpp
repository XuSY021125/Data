#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 100     //线性表存储空间的初始分配量
#define LISTINCREMENT 10       //线性表空间的分配增量

typedef struct
{
	ElemType* elem;				//存储空间基址
	int length;					//当前长度
	int listsize;				//当前分配的存储容量（以sizeof(ElemType)为单位）
}SqList;

Status InitList_Sq(SqList* L)	//构造一个空的线性表L
{
	(*L).elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(*L).elem)
		return overflow;						//存储空间失败   
	(*L).length = 0;							//空表长度为0
	(*L).listsize = LIST_INIT_SIZE;				//初始存储容量
	return OK;
}

Status CreateList_Sq(SqList* L)
{
	int i, n;
	printf("请输入线性表长度\nn=");
	scanf("%d", &n);
	(*L).length = n;
	(*L).length = n;
	printf("\n输入线性表L:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &((*L).elem[i]));
	return OK;
}

Status DestroyList_Sq(SqList* L)                     //销毁线性表L
{
	if ((*L).elem)
		free((*L).elem);                     //释放线性表占据的所有存储空间
	return OK;
}

Status ClearList_Sq(SqList* L)                        //将L重置为空表。
{
	(*L).length = 0;                               //将线性表的长度置为0
	return OK;
}

Status ListEmpty_Sq(SqList L)                        //线性表判空。
{
	if (L.length == 0)
		return TRUE;                         //若L为空，则返回TURE
	else
		return FALSE;                        //若L不为空，则返回FALSE
}

Status ListLength_Sq(SqList L)                       //返回线性表的长度
{
	return(L.length);
}

Status GetElem_Sq(SqList L, int i, ElemType* e)       //用e返回L中的第i个数据元素的值
{
	if (i<1 || i>L.length)  return ERROR;            //i值不合法
	*e = L.elem[i - 1];                               //将第i个数据元素的值赋给e
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
	*pre_e = L.elem[i - 2];                            //将cur_e 的前驱赋值给pre_e
	return OK;
}

Status NextElem_Sq(SqList L, int i, ElemType cur_e, ElemType* next_e)
{
	i = LocateElem_Sq(L, cur_e);
	if (i == ListLength_Sq(L) || i > ListLength_Sq(L)) return 0;
	*next_e = L.elem[i];                            //将cur_e的后继赋值给next_e
	return OK;
}

Status ListInsert_Sq(SqList* L, int i, ElemType e)     //在线性表L中的第i个位置之前插入新的元素e

{
	ElemType* newbase, * p, * q;
	if (i<1 || i>(*L).length + 1)return ERROR;         //i值不合法
	if ((*L).length >= (*L).listsize)
	{
		newbase = (ElemType*)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);         //存储分配失败
		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;          //新基址
	}
	q = &(*L).elem[i - 1];                             //q为插入位置
	for (p = &((*L).elem[(*L).length - 1]); p >= q; --p)
		*(p + 1) = *p;                             //插入位置及之后的元素右移
	*q = e;                                      //插入e
	++(*L).length;                         //表长增1
	return OK;
}

Status ListDelete_Sq(SqList* L, int i, ElemType* e)      //在线性表L中删除第i个元素，并用e返回其值
{
	ElemType* p, * q;
	if (i<1 || i>(*L).length)return ERROR;       //i值不合法
	p = &((*L).elem[i - 1]);                       // p为被删除元素的位置
	*e = *p;                                     //被删除元素的值赋给e
	q = (*L).elem + (*L).length - 1;                 //表尾元素的位置
	for (++p; p <= q; ++p)
		*(p - 1) = *p;                         //被删除元素之后的元素左移
	--(*L).length;                             //表长减1
	return OK;
}

Status ListTraverse_Sq(SqList L, int i)              //线性表L的遍历
{
	printf("线性表为: ");
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
		printf("1:判断线性表是否为空\n");
		printf("2:查询线性表的长度\n");
		printf("3:查找线性表的第i个元素\n");
		printf("4:查找值为x的元素所在的位置\n");
		printf("5:数据元素x的前驱为\n");
		printf("6:数据元素x的后继为\n");
		printf("7:在线性表第i个位置前插入新元素x\n");
		printf("8:删除线性表第i个元素，返回其值\n");
		printf("9:遍历线性表\n");
		printf("10:清空线性表\n");
		printf("0:结束\n");
		printf("**************************************\n");
		printf("请输入选择：");
		scanf("%d", &select);
		switch (select) {
		case 1: if (ListEmpty_Sq(L))
			printf("线性表为空\n");
			  else
			printf("线性表非空\n"); break;

		case 2:ListLength_Sq(L);
			printf("线性表的长度为%d\n", (L.length)); break;

		case 3: printf("\ni=");
			scanf("%d", &i);
			if (GetElem_Sq(L, i, &e) == ERROR)
				printf("i值不合法\n");
			else
				printf("第%d个元素的值为%d\n", i, e); break;

		case 4:printf("\nx=");
			scanf("%d", &e);
			i = LocateElem_Sq(L, e);
			if (i <= L.length)
				printf("第%d个元素的值为%d\n", i, e);
			else
				printf("线性表中没有值为%d的元素\n", e); break;

		case 5:printf("\nx=");
			scanf("%d", &t);
			if (PriorElem_Sq(L, i, t, &e) == 1)
				printf("元素%d的前驱为%d\n\n", t, e);
			else
				printf("元素%d无前驱\n", t); break;

		case 6:printf("\nx=");
			scanf("%d", &t);
			if (NextElem_Sq(L, i, t, &e) == 1)
				printf("元素%d的后继为%d\n\n", t, e);
			else
				printf("元素%d无后继\n", t); break;

		case 7:printf("\ni=");
			scanf("%d", &i, &e);
			printf("\nx=");
			scanf("%d", &e);
			if (ListInsert_Sq(&L, i, e) == ERROR)
				printf("i值不合法\n\n");
			else {
				printf("新的线性表为: ");
				for (i = 0; i < L.length; i++)
					printf("%4d", (L.elem[i]));
				printf("\n\n");
			}break;

		case 8:printf("\ni=");
			scanf("%d", &i);
			if (ListDelete_Sq(&L, i, &e) == ERROR)
				printf("i值不合法\n\n");
			else {
				printf("被删除的第%d个元素的值为%d\n", i, e);
				printf("新的线性表为:");
				for (i = 0; i < L.length; i++)
					printf("%4d", (L.elem[i]));
				printf("\n\n");
			} break;

		case 9:ListTraverse_Sq(L, i); break;

		case 10:ClearList_Sq(&L);
			printf("清空线性表成功,线性表长度是%d \n\n", L.length); break;

		case 0: printf("操作结束\n"); break;
		default:printf("输入选择出错! \n");
		}
	} while (select != 0);
	DestroyList_Sq(&L);
}
