#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2;

    printf("Enter an operator (+, -, *, /, %%, ^): ");
    if (scanf(" %c", &operator) != 1) {
        printf("Error reading operator.\n");
        return 1;
    }

    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &num1, &num2) != 2) {
        printf("Error reading numbers.\n");
        return 1;
    }

    switch (operator) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            } else {
                printf("Error! Division by zero.\n");
            }
            break;
        case '%':
            if (num2 != 0) {
                double r = fmod(num1, num2);
                printf("%.2lf %% %.2lf = %.2lf\n", num1, num2, r);
            } else {
                printf("Error! Division by zero.\n");
            }
            break;
        case '^':
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, pow(num1, num2));
            break;
        default:
            printf("Error! Operator is not correct.\n");
    }

    return 0;
}