#include <stdio.h>
#include <string.h>

enum States
{
    S0, // Start state
    S1, // After first '/'
    S2, // Single-line comment
    S3, // Multi-line comment
    S4, // After '*' in multi-line comment
    S5, // End of multi-line comment
    S6  // Invalid state
};

enum States dfa_comment_checker(char input_string[])
{
    enum States state = S0; // Initial state
    int i = 0;
    char ch;

    while ((ch = input_string[i]) != '\0')
    {
        switch (state)
        {
        case S0:
            if (ch == '/')
                state = S1;
            else
                state = S6;
            break;

        case S1:
            if (ch == '/')
                state = S2;
            else if (ch == '*')
                state = S3;
            else
                state = S6;
            break;

        case S2:
            state = S2;
            break;

        case S3:
            if (ch == '*')
                state = S4;
            else
                state = S3;
            break;

        case S4:
            if (ch == '/')
                state = S5;
            else if (ch == '*')
                state = S4;
            else
                state = S3;
            break;

        case S5:
            state= S5;
            break;
        }

        i++;
    }

    return state;
}

int main()
{
    char input_string[100];

    printf("Enter a string to check for comments: ");
    gets(input_string);

    enum States final_state = dfa_comment_checker(input_string);

    if (final_state == S2)
        printf("\nThe input contains a valid single-line comment.\n");
    else if (final_state == S5)
        printf("\nThe input contains a valid multi-line comment.\n");
    else
        printf("\nThe input does not contain a valid comment.\n");
    printf("\nName: Umesh Pariyar\nRoll No: 20\nLab No: 5");
    return 0;
}
