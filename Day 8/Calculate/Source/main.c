// Nhập vào bàn phím: 2+3-(6*8) =?
// Nhập vào phương trình bậc nhất: 256*x-965 =0 => x=?
// Nhập vào phương trình bậc 2: 2x^2 + 4x -6 =0 => x1, x2?
// char *input "" Sử dụng vòng lặp duyệt hết từng kí tự trong chuỗi

#include "../Head/main.h"

int checkType(char *input)
{
    int flag = 0;
    int i;
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] == '^')
            return 2;
        if (input[i] == 'x')
            flag = 1;
    }

    if (flag == 1)
        return 1;
    return 0;
}

void removeSpaces(char *str)
{
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

int main()
{
    char input[1000] ;
    fgets(input, sizeof(input), stdin);

    // Xóa ký tự newline ở cuối chuỗi
    input[strcspn(input, "\n")] = '\0';

    int check = checkType(input);
    removeSpaces(input);
    switch (check)
    {
    case 0:
        tinhBieuThuc(input);
        break;
    case 1:
        giaiPTBac1(input);
        break;
    default:
        giaiPTBac2(input);
        break;
    }
    return 0;
}