#include <stdio.h>
#include <string.h>

int main() {
    char str[3];
    int valid = 0;

    printf("Enter value to be identified: ");
    scanf("%s", str);

    if (((str[0] == '&' || str[0] == '|') && str[0] == str[1]) || (str[0] == '!' && str[1] == '\0')) {
        printf("\nIt is a Logical operator");
        valid = 1;
    }

    char relational[4] = {'<', '>', '!', '='};
    for (int i = 0; i < 4; i++) {
        if (str[0] == relational[i] && (str[1] == '=' || str[1] == '\0')) {
            printf("\nIt is a Relational Operator");
            valid = 1;
            break;
        }
    }

    char bitwise[4] = {'&', '^', '~', '|'};
    for (int i = 0; i < 4; i++) {
        if ((str[0] == bitwise[i] && str[1] == '\0') || ((str[0] == '<' || str[0] == '>') && str[1] == str[0])) {
            printf("\nIt is a Bitwise Operator");
            valid = 1;
            break;
        }
    }

    if (str[0] == '?' && str[1] == ':') {
        printf("\nIt is a Ternary operator");
        valid = 1;
    }

    char arithmetic[5] = {'+', '-', '*', '/', '%'};
    for (int i = 0; i < 5; i++) {
        if ((str[0] == '+' || str[0] == '-') && str[0] == str[1]) {
            printf("\nIt is a Unary operator");
            valid = 1;
            break;
        } else if ((str[0] == arithmetic[i] && str[1] == '=') || (str[0] == '=' && str[1] == ' ')) {
            printf("\nIt is an Assignment operator");
            valid = 1;
            break;
        } else if (str[0] == arithmetic[i] && str[1] == '\0') {
            printf("\nIt is an Arithmetic operator");
            valid = 1;
            break;
        }
    }

    if (!valid) {
        printf("\nThe input is not a valid operator");
    }
    printf("\n\nName: Umesh Pariyar\nRoll No: 20\nLab No: 9");
    return 0;
}
