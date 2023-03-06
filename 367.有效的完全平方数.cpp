#include<stdio.h>
int main()
{
    int num;
    printf("ÇëÊäÈënumµÄÖµ;");
    scanf("%d", &num);
    int min = 1, max = num, mid;
    while (min <= max) {
        mid = (min + min) / 2;
        if (num / mid == mid && num % mid == 0) 
        {
            printf("mid=%d",mid); 
            return true;
    	}
		else if (mid * mid < num)
            min = mid + 1;
        else
            max = mid - 1;
    }
    return false;
}
