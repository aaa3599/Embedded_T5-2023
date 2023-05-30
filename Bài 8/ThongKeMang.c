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

void thongke(uint8_t arr[], uint8_t n){
    int dem = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==arr[i+1]) 
        {
            dem++;
            continue;
        }
        printf ("So %d xuat hien %u lan \n", arr[i], dem);
        dem = 1;
    }
    
}

int main()
{
    uint8_t arr[]={5,6,9,8,3,12,5,5,6,8,12,14,14,10,12};
    uint8_t n = sizeof(arr)/sizeof(uint8_t);
    sortList(arr, n );
    thongke(arr, n);

}