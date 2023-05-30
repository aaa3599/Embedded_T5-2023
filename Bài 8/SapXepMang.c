//Cho mang ngau nhien , viet chuong trinh sap xep tu be den lon
#include<stdio.h>
#include<stdint.h>

void swap(uint8_t *a, uint8_t *b){
    uint8_t temp =0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sortList(uint8_t arr[], uint8_t n ){
    
    for (int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]) swap(arr+i, arr+j);
        }
    }

}

int main(){
    uint8_t arr[]={1,6,9,8,23,6,45,68,3};
    uint8_t n = sizeof(arr)/sizeof(uint8_t);
    sortList(arr, n );
    printf("\nMang da sap xep la: ");
    for(int i = 0; i < n; i++){
        printf("%5d", arr[i]);
    }
}