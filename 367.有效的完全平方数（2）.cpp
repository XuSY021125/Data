#include<stdio.h>
int main()
{
    int num;
    printf("ÇëÊäÈënumµÄÖµ;");
    scanf("%d", &num);
    if(num==0)
    {
        return false;
    }
    int i = 1;
    while (num > 0)
    {
        num -= i;
        i += 2;
    }
    return num == 0 ? true : false;

}
