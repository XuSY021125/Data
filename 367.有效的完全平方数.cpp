#include<stdio.h>
int main()
{
    int num;
    printf("ÇëÊäÈënumµÄÖµ;");
    scanf_s("%d", &num);
    int min = 1, max = num, mid;
    while (min <= max) {
        mid = (min + min) / 2;
        if (num / mid == mid && num % mid == 0) 
            return true;
        else if (num / mid < mid)
            max = mid - 1;
        else
            min = mid + 1;
    }
    return false;
}