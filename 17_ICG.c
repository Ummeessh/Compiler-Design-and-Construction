#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char expr[100];
int tempCount = 1;

void generate3AC() {
    int i = 0, j = 0;
    char stack[100];
    int top = -1;

    char lhs;
    int startIdx = 0;

    // Check if expression contains assignment (e.g., x = a + b * c)
    if (isalpha(expr[0]) && expr[1] == '=') {
        lhs = expr[0];
        startIdx = 2;
    } else {
        lhs = 'R'; // Default result target if no LHS provided
        startIdx = 0;
    }

    printf("\nThree Address Code Generation:\n");
    printf("-------------------------------\n");

    // Process Multiplication and Division first (Higher Precedence)
    char tempExpr[100];
    int tLen = 0;

    for (i = startIdx; expr[i] != '\0'; i++) {
        if ((expr[i] == '*' || expr[i] == '/') && isalpha(expr[i - 1]) && isalpha(expr[i + 1])) {
            printf("t%d = %c %c %c\n", tempCount, expr[i - 1], expr[i], expr[i + 1]);

            // Replace processed operation with temporary variable symbol
            tLen--;
            tempExpr[tLen++] = '0' + tempCount;
            tempCount++;
            i++;
        } else {
            tempExpr[tLen++] = expr[i];
        }
    }
    tempExpr[tLen] = '\0';

    // Process Addition and Subtraction (Lower Precedence)
    char prevOperand = '\0';

    for (i = 0; tempExpr[i] != '\0'; i++) {
        if (tempExpr[i] == '+' || tempExpr[i] == '-') {
            char op = tempExpr[i];
            char left = (prevOperand != '\0') ? prevOperand : tempExpr[i - 1];
            char right = tempExpr[i + 1];

            // Print temporary variable string
            if (isdigit(left) && isdigit(right)) {
                printf("t%d = t%c %c t%c\n", tempCount, left, op, right);
            } else if (isdigit(left)) {
                printf("t%d = t%c %c %c\n", tempCount, left, op, right);
            } else if (isdigit(right)) {
                printf("t%d = %c %c t%c\n", tempCount, left, op, right);
            } else {
                printf("t%d = %c %c %c\n", tempCount, left, op, right);
            }

            prevOperand = '0' + tempCount;
            tempCount++;
            i++;
        }
    }

    if (prevOperand != '\0') {
        printf("%c = t%c\n", lhs, prevOperand);
    } else if (tempCount > 1) {
        printf("%c = t%d\n", lhs, tempCount - 1);
    } else {
        printf("%c = %c\n", lhs, tempExpr[0]);
    }
}

int main() {
    printf("Enter expression: ");
    scanf("%s", expr);

    generate3AC();

    printf("\nName: Umesh Pariyar\nRoll No: 20\nLab No: 17");
    return 0;
}
