#include <stdio.h>

extern int count;
extern void dem();

static void test(){
    static int a = 10;
    printf("%d\n",a);
    a++;
}

int main(){
    
    dem();
    printf("count:%d\n",count);
    return 0;
}