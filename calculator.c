#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int is_integer(double d) {
    double ip;
    return modf(d, &ip) == 0.0;
}

static double factorial_double(double n, int *err) {
    if (n < 0 || !is_integer(n)) {
        *err = 1;
        return 0.0;
    }
    unsigned long long m = (unsigned long long)n;
    double res = 1.0;
    for (unsigned long long i = 1; i <= m; ++i) {
        res *= (double)i;
    }
    *err = 0;
    return res;
}

static void print_usage(const char *prog) {
    printf("Usage: %s <op> <num1> [num2]\n", prog);
    printf("Operators: + - * / %% ^ (binary), sqrt (or s) (unary), fact (or factorial or !) (unary)\n");
}

int main(int argc, char **argv) {
    char opbuf[32] = {0};
    char opch = 0;
    double num1 = 0.0, num2 = 0.0;

    if (argc > 1) {
        /* CLI mode */
        strncpy(opbuf, argv[1], sizeof(opbuf)-1);
        if (argv[2]) num1 = strtod(argv[2], NULL);
        if (argv[3]) num2 = strtod(argv[3], NULL);
    } else {
        /* Interactive mode */
        char line[256];
        printf("Enter an operator (+, -, *, /, %%, ^, sqrt, fact): ");
        if (!fgets(line, sizeof(line), stdin)) return 1;
        if (sscanf(line, "%31s", opbuf) != 1) {
            printf("Error: invalid operator input.\n");
            return 1;
        }
        /* decide unary vs binary */
        if (strcmp(opbuf, "sqrt") == 0 || strcmp(opbuf, "s") == 0 || strcmp(opbuf, "!") == 0 || strcmp(opbuf, "fact") == 0 || strcmp(opbuf, "factorial") == 0) {
            printf("Enter one number: ");
            if (!fgets(line, sizeof(line), stdin)) return 1;
            num1 = strtod(line, NULL);
        } else {
            printf("Enter two numbers: ");
            if (!fgets(line, sizeof(line), stdin)) return 1;
            char *p = line;
            char *endp = NULL;
            num1 = strtod(p, &endp);
            if (endp == p) { printf("Error: invalid first number.\n"); return 1; }
            p = endp;
            num2 = strtod(p, &endp);
            if (endp == p) { printf("Error: invalid second number.\n"); return 1; }
        }
    }

    /* normalize operator: if single-char operator provided as opbuf[0], use it */
    if (strlen(opbuf) == 1) opch = opbuf[0];

    if (opch) {
        switch (opch) {
            case '+':
                printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
                break;
            case '/':
                if (num2 != 0.0) printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
                else printf("Error! Division by zero.\n");
                break;
            case '%':
                if (num2 != 0.0) printf("%.2f %% %.2f = %.2f\n", num1, num2, fmod(num1, num2));
                else printf("Error! Division by zero.\n");
                break;
            case '^':
                printf("%.2f ^ %.2f = %.2f\n", num1, num2, pow(num1, num2));
                break;
            default:
                printf("Error! Operator is not correct.\n");
        }
    } else {
        /* string operators */
        if (strcmp(opbuf, "sqrt") == 0 || strcmp(opbuf, "s") == 0) {
            if (num1 < 0.0) printf("Error! Square root of negative number.\n");
            else printf("sqrt(%.2f) = %.2f\n", num1, sqrt(num1));
        } else if (strcmp(opbuf, "fact") == 0 || strcmp(opbuf, "factorial") == 0 || strcmp(opbuf, "!") == 0) {
            int err = 0; double f = factorial_double(num1, &err);
            if (err) printf("Error! Factorial requires non-negative integer input.\n");
            else printf("%.0f! = %.2f\n", num1, f);
        } else {
            printf("Error! Operator is not correct.\n");
        }
    }

    return 0;
}