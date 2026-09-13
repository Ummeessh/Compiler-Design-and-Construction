#include<stdio.h>

enum states { q0, q1 };

int main()
{
    enum states curr_state = q0;
    char input[20], ch;
    int i = 0;

    printf("Enter a string: ");
    gets(input);

    ch = input[i];
    while (ch != '\0')
    {
        switch (curr_state)
        {
            case q0:
                if (ch == 'a')
                    curr_state = q1;
                else
                    curr_state = q0;
                break;

            case q1:
                if (ch == 'a')
                    curr_state = q0;
                else
                    curr_state = q1;
                break;
        }
        ch = input[++i];
    }

    if (curr_state == q1)
        printf("\nThe string %s has an odd number of a's and is accepted.", input);
    else
        printf("\nThe string %s does not have an odd number of a's and is rejected.", input);
    printf("\n\nName: Umesh Pariyar\nRoll No: 20\nLab No: 4");

    return 0;
}
