#include<stdio.h>

enum states { q0, q1, q2, qf };

int main()
{
    enum states curr_state = q0;
    char string[20], ch;
    int i = 0;

    printf("Enter a string: ");
    gets(string);  // Note: `gets()` is unsafe. Consider using `fgets()` in real-world code.

    ch = string[i];
    while(ch != '\0')
    {
        switch(curr_state)
        {
        case q0:
            if(ch == '0')
                curr_state = q1;
            else
                curr_state = q0;
            break;

        case q1:
            if(ch == '0')
                curr_state = q2;
            else
                curr_state = q0;
            break;

        case q2:
            if(ch == '0')
                curr_state = q2;
            else
                curr_state = qf;
            break;

        case qf:
            if(ch == '0' || ch == '1')
                curr_state = qf;
            break;
        }
        ch = string[++i];
    }

    if(curr_state == qf)
        printf("\nThe string %s is accepted.", string);
    else
        printf("\nThe string %s is not accepted.", string);
    printf("\n\nName: Umesh Pariyar\nRoll No: 20\nLab No: 3(iii)");

    return 0;
}
