//tinh gia cuoc taxi
//di taxi duoi 1km gia 14000
//di<= 30km gia 10 nghin/km
//di>=30km gia 8 nghin/km

#include <stdio.h>

unsigned calculateTaxiFare( unsigned s){
    const unsigned sLowMax = 1;
    const unsigned sMidMax = 30;
    unsigned fare=0;
    if (s<=sLowMax) return 14;
    else if(s<=sMidMax) {
        unsigned sMid = s - sLowMax;
        fare = sMid*10 + 14; 
    }else
    {
        unsigned sHigh = s - sMidMax;
        fare = sHigh*8 + 29*10 +14;
    }
    return fare;
}
    

int main(){
    unsigned s = 132;
    unsigned fare = calculateTaxiFare(s);
    printf("Gia tien taxi la %u000 VND",fare);

}