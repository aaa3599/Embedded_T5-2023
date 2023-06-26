#include "../Head/main.h"

void solve_quadratic_equation(const char* equation) {
    float a, b, c;
    int result = sscanf(equation, "%f*x^2%f*x%f", &a, &b, &c);
    
    if (result == 3) {
        // Tính delta
        float delta = b * b - 4 * a * c;
        
        // Kiểm tra giá trị của delta để xác định số nghiệm
        if (delta > 0) {
            // Hai nghiệm phân biệt
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Hai nghiem phan biet: x1 = %.2f, x2 = %.2f\n", x1, x2);
        } else if (delta == 0) {
            // Hai nghiệm cùng nhau
            float x = -b / (2 * a);
            printf("Hai nghiem cung nhau: x1 = x2 = %.2f\n", x);
        } else {
            // Không có nghiệm thực
            printf("Phuong trinh khong co nghiem thuc.\n");
        }
    } else {
        printf("Phuong trinh khong hop le.\n");
    }
}

int giaiPTBac2(char input[]) {
    
    solve_quadratic_equation(input);
    
    return 0;
}
