#include<stdio.h>

enum states { q0, q1, qf};

int main()
{
    char input[20];
    enum states curr_state = q0;
    int i = 0;

    printf("Enter a binary string: ");
    gets(input);  // Note: gets() is unsafe; consider using fgets() instead in real-world code

    char ch = input[i];
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
            if(ch == '1')
                curr_state = qf;
            else
                curr_state = q1;
            break;

        case qf:
            if(ch == '0')
                curr_state = q1;
            else
                curr_state = q0;
            break;
        }
        ch = input[++i];
    }

    if(curr_state == qf)
        printf("\nThe string %s is accepted.", input);
    else
        printf("\nThe string %s is not accepted.", input);
    printf("\n\nName: Umesh Pariyar\nRoll No: 20\nLab No: 3(ii)");


    return 0;
}
