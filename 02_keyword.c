#include <stdio.h>
#include <string.h>
#include <ctype.h>


enum states { q0, q1, qd };

char keyword[32][10] =
{
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

int isKeyword(char str[])
{
    for (int i = 0; i < 32; i++)
    {
        if (strcmp(str, keyword[i]) == 0)
            return 1;
    }
    return 0;
}

int isValidIdentifier(char str[])
{
    enum states curr_state = q0;
    int i = 0;
    char ch;

    while ((ch = str[i]) != '\0')
    {
        switch (curr_state)
        {
        case q0:
            if (isalpha(ch) || ch == '_')
                curr_state = q1;
            else
                curr_state = qd;
            break;

        case q1:
            if (isalnum(ch) || ch == '_')
                curr_state = q1;
            else
                curr_state = qd;
            break;

        case qd:
            return 0;
        }
        i++;
    }

    return (curr_state == q1);
}

int main()
{
    char str[50];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isKeyword(str))
    {
        printf("'%s' is a keyword.\n", str);
    }
    else if (isValidIdentifier(str))
    {
        printf("'%s' is a valid identifier.\n", str);
    }
    else
    {
        printf("'%s' is not a valid identifier.\n", str);
    }

    printf("\nName: Umesh Pariyar\nRoll No: 20\nLab No: 2");

    return 0;
}
