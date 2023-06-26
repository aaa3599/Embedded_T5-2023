#include <stdio.h>
#include <stdint.h>

int POARTA = 0b00000000;

typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} pins;

typedef enum
{
    LOW,
    HIGHT
} status;

void pinHigh(pins pin)
{
    POARTA = POARTA | (0b10000000 >> pin);
}

void pinLow(pins pin)
{
    POARTA = POARTA & ~(0b10000000 >> pin);
}

void digitalWrite(pins pin, status st)
{
    if (st == LOW)
    {
        pinLow(pin);
    }
    else
    {
        pinHigh(pin);
    }
}

void ReadByte(uint8_t byte)
{
    uint8_t test = 0b10000000;
    for (int i = 1; i <= 8; i++)
    {
        uint8_t kq = byte & test;
        if (kq == 0)
            printf("0");
        else
            printf("1");
        test >>= 1;
    }
}

int main()
{
    pinHigh(PIN3);
    pinLow(PIN5);
    digitalWrite(PIN6, HIGHT);
    ReadByte(POARTA);
    return 0;
}