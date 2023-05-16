#include <stdio.h>
#include <stdint.h>

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
    uint8_t a = 10;
    ReadByte(a);
    return 0;
}