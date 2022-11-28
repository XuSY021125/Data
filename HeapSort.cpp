#include <stdio.h>
#include <stdlib.h>
#define MAX 9
typedef struct 
{
    int key;
}SqNote;
typedef struct 
{
    SqNote r[MAX];
    int length;
}SqList;
void HeapAdjust(SqList * H,int s,int m)
{
    SqNote rc=H->r[s];
    for (int j=2*s; j<=m; j*=2) 
	{
        if (j+1<m && (H->r[j].key<H->r[j+1].key)) 
		{
            j++;
        }
        if (!(rc.key<H->r[j].key)) 
		{
            break;
        }
        H->r[s]=H->r[j];
        s=j;
    }
    H->r[s]=rc;
}
//交换两个记录的位置
void swap(SqNote *a,SqNote *b)
{
    int key=a->key;
    a->key=b->key;
    b->key=key;
}
void HeapSort(SqList *H)
{
    for (int i=H->length/2; i>0; i--) 
	{
        HeapAdjust(H, i, H->length);
    }
    for (int i=H->length; i>1; i--) 
	{
        swap(&(H->r[1]), &(H->r[i]));
        HeapAdjust(H, 1, i-1);
    }
}
int main() 
{
    SqList * L=(SqList*)malloc(sizeof(SqList));
    L->length=8;
    L->r[1].key=49;
    L->r[2].key=38;
    L->r[3].key=65;
    L->r[4].key=97;
    L->r[5].key=76;
    L->r[6].key=13;
    L->r[7].key=27;
    L->r[8].key=49;
    HeapSort(L);
    for (int i=1; i<=L->length; i++) 
	{
        printf("%d ",L->r[i].key);
    }
    return 0;
}
