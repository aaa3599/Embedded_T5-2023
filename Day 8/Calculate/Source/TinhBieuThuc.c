#include "../Head/main.h"

typedef enum
{
    NUMBER,
    OPERATOR,
    END
} TyepMath;

typedef struct
{
    TyepMath key;
    union
    {
        uint16_t number;
        char operator;
    } value;

} typeMaths;

void stringToDec(char input[], typeMaths output[])
{
    uint16_t number = 0;
    uint8_t i = 0;
    while (*input != '\0')
    {
        if (*input >= '0' && *input <= '9')
        {
            number = 10 * number + *input - '0';
            input++;
            continue;
        }
        if (number != 0)
        {
            output[i].key = NUMBER;
            output[i].value.number = number;
            number = 0;
            i++;
        }
        if (*input == '+' || *input == '-' || *input == '*' || *input == '/')
        {
            output[i].key = OPERATOR;
            output[i].value.operator= * input;
            input++;
            i++;
            continue;
        }
    }
    output[i].key = NUMBER;
    output[i].value.number = number;
    i++;
    output[i].key = END;
}

void mulAndDiv(typeMaths output[])
{
    int i;
    for (i = 1; output[i].key != END; i += 2)
    {
        int temp;
        if (output[i].value.operator== '*' || output[i].value.operator== '/')
        {
            if (output[i].value.operator== '*')
            {
                temp = output[i - 1].value.number * output[i + 1].value.number;
            }
            else
            {
                temp = output[i - 1].value.number / output[i + 1].value.number;
            }
            output[i - 1].value.number = 0;
            output[i + 1].value.number = temp;
        }
    }
}

int plusAndMinus(typeMaths output[])
{
    int result = output[0].value.number;
    int flag = 0, i;
    for (i = 1; output[i].key != END; i += 2)
    {
        switch (output[i].value.operator)
        {
        case '+':
            flag = 0;
            break;
        case '-':
            flag = 1;
            break;
        }
        if (flag == 0)
            result += output[i + 1].value.number;
        if (flag == 1)
            result -= output[i + 1].value.number;
    }
    return result;
}

int tinhBieuThuc(char input[])
{
    typeMaths output[20];
    stringToDec(input, output);
    int i;
    for (i = 0; output[i].key != END; i++)
    {
        if (output[i].key == NUMBER)
        {
            printf("key:NUMBER, valua:%d\n", output[i].value.number);
        }
        else
        {
            printf("key:OPERATOR, valua:%c\n", output[i].value.operator);
        }
    }
    mulAndDiv(output);
    printf("Gia tri bieu thuc la: %d\n", plusAndMinus(output));
    return 0;
}