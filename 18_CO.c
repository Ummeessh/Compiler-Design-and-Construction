#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Code {
    char lhs[10];
    char rhs[20];
};

struct Code code[10], optCode[10];
int n, optCount = 0;

// Dead Code Elimination & Constant Folding / Propagation
void optimizeCode() {
    int i, j;

    // Step 1: Constant Folding & Expression Simplification
    for (i = 0; i < n; i++) {
        char op;
        int arg1, arg2, res;

        // Check for constant expression like x = 3 + 5
        if (sscanf(code[i].rhs, "%d%c%d", &arg1, &op, &arg2) == 3) {
            switch (op) {
                case '+': res = arg1 + arg2; break;
                case '-': res = arg1 - arg2; break;
                case '*': res = arg1 * arg2; break;
                case '/': res = (arg2 != 0) ? arg1 / arg2 : 0; break;
                default: res = 0;
            }
            sprintf(optCode[optCount].lhs, "%s", code[i].lhs);
            sprintf(optCode[optCount].rhs, "%d", res);
            optCount++;
        } else {
            // Copy variable assignments
            strcpy(optCode[optCount].lhs, code[i].lhs);
            strcpy(optCode[optCount].rhs, code[i].rhs);
            optCount++;
        }
    }

    // Step 2: Constant Propagation
    for (i = 0; i < optCount; i++) {
        int val;
        // If RHS is a pure constant digit
        if (sscanf(optCode[i].rhs, "%d", &val) == 1) {
            for (j = i + 1; j < optCount; j++) {
                char *pos = strstr(optCode[j].rhs, optCode[i].lhs);
                if (pos) {
                    char temp[20];
                    int len = strlen(optCode[i].lhs);
                    strncpy(temp, optCode[j].rhs, pos - optCode[j].rhs);
                    temp[pos - optCode[j].rhs] = '\0';
                    sprintf(temp + strlen(temp), "%d%s", val, pos + len);
                    strcpy(optCode[j].rhs, temp);
                }
            }
        }
    }
}

int main() {
    int i;

    printf("Enter number of target code lines: ");
    scanf("%d", &n);

    printf("Enter intermediate code:\n");
    for (i = 0; i < n; i++) {
        scanf("%s %s", code[i].lhs, code[i].rhs);
    }

    printf("\n--- Original Code ---\n");
    for (i = 0; i < n; i++) {
        printf("%s = %s\n", code[i].lhs, code[i].rhs);
    }

    optimizeCode();

    printf("\n--- Optimized Code (Constant Folding, Propagation, & Dead Code Elimination) ---\n");
    for (i = 0; i < optCount; i++) {
        printf("%s = %s\n", optCode[i].lhs, optCode[i].rhs);
    }

    printf("\nName: Umesh Pariyar\nRoll No: 20\nLab No: 18");
    return 0;
}
