#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK 100
#define MAX_INPUT 100

// Terminals: 0 = id, 1 = +, 2 = *, 3 = $
// Non-Terminals: 0 = E, 1 = T

// ACTION TABLE
// Positive = Shift
// Negative = Reduce
// 99 = Accept
// 0 = Error
//
// Rules:
// 1. E -> E + T
// 2. E -> E * T
// 3. E -> T
// 4. T -> id

int actionTable[8][4] = {
    { 1,  0,  0,  0},   // State 0
    { 0, -4, -4, -4},   // State 1
    { 0,  5,  4, 99},   // State 2
    { 0, -3, -3, -3},   // State 3
    { 1,  0,  0,  0},   // State 4
    { 1,  0,  0,  0},   // State 5
    { 0, -2, -2, -2},   // State 6
    { 0, -1, -1, -1}    // State 7
};

// GOTO TABLE
// Non-Terminals: 0 = E, 1 = T

int gotoTable[8][2] = {
    {2, 3},   // State 0
    {0, 0},   // State 1
    {0, 0},   // State 2
    {0, 0},   // State 3
    {0, 6},   // State 4
    {0, 7},   // State 5
    {0, 0},   // State 6
    {0, 0}    // State 7
};

// Production lengths
int prodLen[5] = {
    0,
    3,  // Rule 1: E -> E + T
    3,  // Rule 2: E -> E * T
    1,  // Rule 3: E -> T
    1   // Rule 4: T -> id
};

// LHS: 0 = E, 1 = T
int prodLHS[5] = {
    0,
    0,  // Rule 1
    0,  // Rule 2
    0,  // Rule 3
    1   // Rule 4
};

int stateStack[MAX_STACK];
int top = -1;

void push(int state)
{
    if (top < MAX_STACK - 1)
        stateStack[++top] = state;
}

int pop()
{
    if (top >= 0)
        return stateStack[top--];

    return -1;
}

int peek()
{
    return stateStack[top];
}

int getTerminalIndex(char token)
{
    if (token == 'i') return 0;  // id
    if (token == '+') return 1;
    if (token == '*') return 2;
    if (token == '$') return 3;

    return -1;
}

int main()
{
    char input[MAX_INPUT];

    printf("CLR(1) Parser Implementation\n");

    printf("Grammar:\n");
    printf(" 1. E -> E + T\n");
    printf(" 2. E -> E * T\n");
    printf(" 3. E -> T\n");
    printf(" 4. T -> id ('i')\n\n");

    printf("Enter input string: ");
    scanf("%s", input);

    push(0);

    int ip = 0;

    printf("\n%-15s %-15s %-20s\n",
           "Stack Top State", "Input Token", "Action");

    printf("--------------------------------------------------------\n");

    while (1)
    {
        int currentState = peek();
        char currentToken = input[ip];

        int termIdx = getTerminalIndex(currentToken);

        if (termIdx == -1)
        {
            printf("\nError: Invalid token '%c'.\n", currentToken);
            break;
        }

        int action = actionTable[currentState][termIdx];

        // Shift
        if (action > 0 && action != 99)
        {
            printf("%-15d %-15c Shift %d\n",
                   currentState, currentToken, action);

            push(action);
            ip++;
        }

        // Reduce
        else if (action < 0)
        {
            int rule = -action;

            printf("%-15d %-15c Reduce by Rule %d\n",
                   currentState, currentToken, rule);

            for (int k = 0; k < prodLen[rule]; k++)
                pop();

            int topState = peek();
            int lhs = prodLHS[rule];

            int nextState = gotoTable[topState][lhs];

            push(nextState);
        }

        // Accept
        else if (action == 99)
        {
            printf("%-15d %-15c ACCEPT\n",
                   currentState, currentToken);

            printf("\nInput string parsed successfully!\n");
            break;
        }

        // Error
        else
        {
            printf("%-15d %-15c ERROR\n",
                   currentState, currentToken);

            printf("\nSyntax Error: String rejected.\n");
            break;
        }
    }
    printf("\nName: Umesh Pariyar\nRoll No: 20\nLab No: 16");
    return 0;
}
