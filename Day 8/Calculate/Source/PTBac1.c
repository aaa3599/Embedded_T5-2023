#include "../Head/main.h"

typedef struct
{
    float a;
    float b;
    char operator;
} LinearEquation;

LinearEquation parseEquation(char *equation)
{
    LinearEquation result;

    // Tách giá trị của a và b từ chuỗi phương trình
    sscanf(equation, "%f*x%c%f", &result.a, &result.operator, & result.b);
    return result;
}

float solveLinearEquation(LinearEquation equation)
{
    if (equation.a == 0)
    {
        if (equation.b == 0)
        {
            printf("Phuong trinh co vo so nghiem.\n");
        }
        else
        {
            printf("Phuong trinh vo nghiem.\n");
        }
    }
    else
    {
        float x;
        if (equation.operator== '+')
        {
            x = -equation.b / equation.a;
        }
        else
        {
            x = equation.b / equation.a;
        }

        printf("Phuong trinh co nghiem x = %.2f\n", x);
        return x;
    }

    return 0;
}

int giaiPTBac1(char input[])
{

    LinearEquation equation = parseEquation(input);
    solveLinearEquation(equation);

    return 0;
}
