%{
#include <stdio.h>

int yylex();
void yyerror(const char *s);
%}

%token NUMBER PLUS MULT

%%

expr:
      expr PLUS term
    | term
    ;

term:
      term MULT factor
    | factor
    ;

factor:
      NUMBER
    | '(' expr ')'
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid expression\n");
}

int main()
{
    printf("Enter an expression: ");

    if (yyparse() == 0)
        printf("Valid expression\n");

    return 0;
}