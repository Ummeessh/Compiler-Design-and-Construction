#include <stdio.h>
#include <ctype.h>

#define MAX 10

char p[MAX][MAX], first[MAX][MAX], follow[MAX][MAX];
int n, nf[MAX], nfol[MAX];

void add(char a[], int *n, char c)
{
    for (int i = 0; i < *n; i++)
        if (a[i] == c)
            return;

    a[(*n)++] = c;
}

void FIRST(char c, char r[], int *nr)
{
    if (!isupper(c))
    {
        add(r, nr, c);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (p[i][0] != c)
            continue;

        for (int j = 2; p[i][j]; j++)
        {

            char temp[MAX];
            int nt = 0;

            FIRST(p[i][j], temp, &nt);

            int eps = 0;

            for (int k = 0; k < nt; k++)
            {
                if (temp[k] == '#')
                    eps = 1;
                else
                    add(r, nr, temp[k]);
            }

            if (!eps)
                break;

            if (!p[i][j + 1])
                add(r, nr, '#');
        }
    }
}

void FOLLOW(char c, char r[], int *nr)
{
    if (c == p[0][0])
        add(r, nr, '$');

    for (int i = 0; i < n; i++)
    {

        for (int j = 2; p[i][j]; j++)
        {

            if (p[i][j] != c)
                continue;

            if (p[i][j + 1])
            {

                char temp[MAX];
                int nt = 0;

                FIRST(p[i][j + 1], temp, &nt);

                int eps = 0;

                for (int k = 0; k < nt; k++)
                {

                    if (temp[k] == '#')
                        eps = 1;
                    else
                        add(r, nr, temp[k]);
                }

                if (eps && p[i][0] != c)
                    FOLLOW(p[i][0], r, nr);
            }

            else if (p[i][0] != c)
            {
                FOLLOW(p[i][0], r, nr);
            }
        }
    }
}

int main()
{
    char done[MAX];
    int d;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (e.g. E=TR, R=+TR | #=EPSILON):\n");

    for (int i = 0; i < n; i++)
        scanf("%s", p[i]);

    printf("\nFIRST:\n");

    d = 0;

    for (int i = 0; i < n; i++)
    {

        int found = 0;

        for (int j = 0; j < d; j++)
        {
            if (done[j] == p[i][0])
                found = 1;
        }

        if (found)
            continue;

        done[d++] = p[i][0];

        int k = 0;

        FIRST(p[i][0], first[i], &k);

        printf("FIRST(%c) = { ", p[i][0]);

        for (int j = 0; j < k; j++)
        {

            printf("%c", first[i][j]);

            if (j < k - 1)
                printf(", ");
        }

        printf(" }\n");
    }

    printf("\n--------------------------------\n\n");

    printf("FOLLOW:\n");

    d = 0;

    for (int i = 0; i < n; i++)
    {

        int found = 0;

        for (int j = 0; j < d; j++)
        {
            if (done[j] == p[i][0])
                found = 1;
        }

        if (found)
            continue;

        done[d++] = p[i][0];

        int k = 0;

        FOLLOW(p[i][0], follow[i], &k);

        printf("FOLLOW(%c) = { ", p[i][0]);

        for (int j = 0; j < k; j++)
        {

            printf("%c", follow[i][j]);

            if (j < k - 1)
                printf(", ");
        }

        printf(" }\n");
    }

    printf("\nName: Umesh Pariyar\nRoll No: 20\nLab No: 7");

    return 0;
}
