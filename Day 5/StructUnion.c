#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
struct SinhVien {
    int maSV;
    char ho[20];
    char ten[20];
    bool gioiTinh;
    char queQuan[100];
};

typedef union Data {
   uint8_t i;
   float f;
   char str[20];
} data; 


int main(){
    struct SinhVien sv;
    data Data;
    printf("Dia chi i: %d\n",&Data.i);
    printf("Dia chi f: %d\n",&Data.f);
    printf("Dia chi f: %d\n",Data.str);
    printf("Dia chi maSV: %d\n",&sv.maSV);
    printf("Dia chi ho: %d\n",sv.ho);
    printf("Dia chi ten: %d\n",sv.ten);
    printf("Dia chi gioiTinh: %d\n",&sv.gioiTinh);

    Data.i = 15;
    Data.f = 28.9056;
    strcpy( Data.str, "C Programming");
    printf("Gia tri Data.i: %d\n",Data.i);
    printf("Gia tri Data.f: %f\n",Data.f);
    printf("Gia tri Data.str: %s\n",Data.str);
}