#include <stdio.h>
#include <ctype.h>
#include <string.h>
void FIRST(char[], char);
void addToResultSet(char[], char);
int numOfProductions;
char productionSet[10][10];

int main()
{
    int i;
    char choice;
    char ch;
    char result[20];

    printf("How many number of productions?: ");
    scanf("%d", &numOfProductions);

    printf("Enter the Production in the form V=(VUT)*\n");

    for (i = 0; i < numOfProductions; i++)
    {
        printf("Enter productions number %d: ", i + 1);
        scanf("%s", productionSet[i]);
    }

    do
    {
        printf("Find the First of: ");
        scanf(" %c", &ch);  // Note the space before %c to consume any leftover whitespace

        // Initialize result to an empty string
        result[0] = '\0';

        FIRST(result, ch);

        printf("\nFIRST(%c) = {", ch);
        for (i = 0; result[i] != '\0'; i++)
        {
            printf("%c", result[i]);
            if (result[i + 1] != '\0')
            {
                printf(", ");
            }
        }
        printf("}\n");

        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);  // Note the space before %c to consume any leftover whitespace
    }
    while (choice == 'y' || choice == 'Y');
    printf("\nName: Umesh Pariyar\nRoll No: 20\nLab No: 6");
    return 0;
}

void FIRST(char* Result, char ch)
{
    int i, j, k;
    char subResult[20];
    int foundEpsilon;

    // Initialize subResult to an empty string
    subResult[0] = '\0';

    // If X is terminal, FIRST(X) = {X}
    if (!isupper(ch))
    {
        addToResultSet(Result, ch);
        return;
    }

    // For each production
    for (i = 0; i < numOfProductions; i++)
    {
        // Check if the production is of the form X -> ...
        if (productionSet[i][0] == ch)
        {
            // If X -> epsilon, add epsilon to FIRST(X)
            if (productionSet[i][2] == '$')
            {
                addToResultSet(Result, '$');
            }
            else
            {
                // For each symbol in the production body
                j = 2;
                while (productionSet[i][j] != '\0')
                {
                    foundEpsilon = 0;

                    // Recursively calculate FIRST
                    FIRST(subResult, productionSet[i][j]);

                    // Add FIRST(Y) to FIRST(X)
                    for (k = 0; subResult[k] != '\0'; k++)
                    {
                        addToResultSet(Result, subResult[k]);
                    }

                    // Check if epsilon is in FIRST(Y)
                    for (k = 0; subResult[k] != '\0'; k++)
                    {
                        if (subResult[k] == '$')
                        {
                            foundEpsilon = 1;
                            break;
                        }
                    }

                    // If epsilon is not in FIRST(Y), stop
                    if (!foundEpsilon)
                    {
                        break;
                    }

                    j++;
                }
            }
        }
    }
}

void addToResultSet(char Result[], char val)
{
    int k;

    // Check if val is already in Result
    for (k = 0; Result[k] != '\0'; k++)
    {
        if (Result[k] == val)
        {
            return;
        }
    }

    // Add val to Result
    Result[k] = val;
    Result[k + 1] = '\0';
}
