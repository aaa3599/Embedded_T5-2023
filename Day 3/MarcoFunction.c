#include <stdio.h>

#define MAX 10

#define SUM(a,b) a+b 

#define CREATE_FUNC(ten_ham, noi_dung)  \
void ten_ham(){                         \
    printf("%s \n ",noi_dung);          \
}

int HIEU(int a,int b){
    return a-b;
}
CREATE_FUNC(test,"this is test");

CREATE_FUNC(abc,"this is abc function");

int main(){
    printf("MAX=%d\n",MAX);
    int a=MAX+5;
    printf("Tong a va b:%d \n", SUM(4,7));
    printf("Hieu a va b:%d \n",HIEU(19,7));
    test();
    abc();

}