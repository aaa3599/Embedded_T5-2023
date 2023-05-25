#include <stdio.h>

void tong(int a, int b){
    printf("\ntong %d va %d la %d",a,b,a+b);
}

void hieu(int a, int b){
    printf("\nhieu %d va %d la %d",a,b,a-b);
}

int tich(int a, int b){
    return a*b;
}

void thuong(int a, int b){
    printf("\nthuong %d va %d la %f",a,b,(float)a/b);
}

void tinhtoan(int a, int b, void (*ptr)(int,int)){
    printf("\nChuong tinh toan");
    ptr(a,b);
}

int main(){
    int a =10;
    void *ptr =&a;
    long long **ptr3=&ptr;
    printf("\n%u",**ptr3);
    int *ptr0 = NULL;
    printf("\na=%d",*(int*)ptr);
    void (*ptr1)(int,int)=NULL;
    ptr1 =tong;
    ptr1(9,7);
    ptr1 =&hieu;
    ptr1(15,18);
    ptr1 =&thuong;
    ptr1(35,20);
    int (*ptr2)(int,int)=&tich;
    printf("\ntich 6 va 7: %d",ptr2(6,7));
    tinhtoan(8,9,&hieu);
    tinhtoan(12,19,hieu);
    printf("\n%u",hieu);
    printf("\n%u",&hieu);
    return 0;
}