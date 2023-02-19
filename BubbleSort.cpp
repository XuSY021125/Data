#include <stdio.h>
//交换 a 和 b 的位置的函数
int main()
{
    int array[8] = {49,38,65,97,76,13,27,49};
    int i, j,temp;
    int key;
    //有多少记录，就需要多少次冒泡，当比较过程，所有记录都按照升序排列时，排序结束
    for (i = 0; i < 8; i++){
        key=0;//每次开始冒泡前，初始化 key 值为 0
        //每次起泡从下标为 0 开始，到 8-i 结束
        for (j = 0; j+1<8-i; j++){
            if (array[j] > array[j+1]){
                key=1;
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
        //如果 key 值为 0，表明表中记录排序完成
        if (key==0) {
            break;
        }
    }
    for (i = 0; i < 8; i++){
        printf("%d ", array[i]);
    }
    return 0;
}

