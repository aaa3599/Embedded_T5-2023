#include <iostream>

class ToanHoc{
    public:
        void tong(int a, int b);
        void tong(int a, int b, int c);
        int tong(int a, double b);
};

void ToanHoc::tong (int a, int b){
    printf ("Tong a va b la: %d\n", a+b);
}

void ToanHoc::tong (int a, int b, int c){
    printf ("Tong a va b va c la: %d\n", a+b+c);
}

int ToanHoc::tong (int a, double b){
    return a+(int)b;
}

template <typename var, typename varB>

var tong (var a, varB b){
    return (var)(a+b);
}

namespace ConOngA{
    int A=10;
}

namespace ConOngB{
    int A=20;
}

int main(){
    ToanHoc th;
    th.tong(1,2);
    th.tong(4,5,6);
    printf("Tong cua d va e %d\n", th.tong(7,12.3));
    printf("Tong cua d va e %f\n", tong(7.1,12));
    printf("A=%d ",ConOngA::A);
    printf("A=%d ",ConOngB::A);
}