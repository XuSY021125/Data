#include <stdio.h>
//���� a �� b ��λ�õĺ���
int main()
{
    int array[8] = {49,38,65,97,76,13,27,49};
    int i, j,temp;
    int key;
    //�ж��ټ�¼������Ҫ���ٴ�ð�ݣ����ȽϹ��̣����м�¼��������������ʱ���������
    for (i = 0; i < 8; i++){
        key=0;//ÿ�ο�ʼð��ǰ����ʼ�� key ֵΪ 0
        //ÿ�����ݴ��±�Ϊ 0 ��ʼ���� 8-i ����
        for (j = 0; j+1<8-i; j++){
            if (array[j] > array[j+1]){
                key=1;
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
        //��� key ֵΪ 0���������м�¼�������
        if (key==0) {
            break;
        }
    }
    for (i = 0; i < 8; i++){
        printf("%d ", array[i]);
    }
    return 0;
}

