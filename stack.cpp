#include <stdio.h>
//Ԫ��elem��ջ
int push(char* a,int top,char elem){
    a[++top]=elem;
    return top;
}
//����Ԫ�س�ջ
int pop(char * a,int top){
    if (top==-1) {
        printf("��ջ");
        return -1;
    }
    printf("��ջԪ�أ�%c\n",a[top]);
    top--;
    return top;
}
int main() {
    char a[100];
    int top=-1;
    top=push(a, top, 'a');
    top=push(a, top, 'b');
    top=push(a, top, 'c');
    top=push(a, top, 'd');
    top=pop(a, top);
    top=pop(a, top);
    top=pop(a, top);
    top=pop(a, top);
    top=pop(a, top);
    return 0;
}
