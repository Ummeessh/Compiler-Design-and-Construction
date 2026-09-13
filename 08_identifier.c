#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isValidIdentifier(char str[])
{
    if (!isalpha(str[0]) && str[0] != '_')
    {
        return 0;
    }
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isValidIdentifier(str))
    {
        printf("'%s' is a valid identifier.\n", str);
    }
    else
    {
        printf("'%s' is not a valid identifier.\n", str);
    }
    printf("\nName: Umesh Pariyar\nRoll No: 20\nLab No: 8");
    return 0;
}
